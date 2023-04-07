import pandas as pd
import json
import requests
from concurrent.futures import ThreadPoolExecutor

# 한국거래소에서 종목 코드 받아옵니다. [0]은 헤더를 첫번째 행으로 지정하기 위해 사용 했습니다.
code_df = pd.read_html('http://kind.krx.co.kr/corpgeneral/corpList.do?method=download&searchType=13')[0]
# 종목코드가 6자리이기 때문에 6자리를 맞춰주기 위해 설정해줍니다.
code_df.종목코드 = code_df.종목코드.map('{:06d}'.format)
# 우리에게 필요한 회사명과 종목코드만 남깁니다.
code_df = code_df[['회사명', '종목코드']]
# 리스트 형식으로 변경하면 네이버증권API 사용을 위한 준비가 끝납니다.
stock_list = code_df.values.tolist()

# multiprocessing을 위해 함수로 작성합니다.
def func(stock_set):
    # 회사명을 가져옵니다.
    item_name = stock_set[0]
    # 종목코드를 가져옵니다.
    item_code = stock_set[1]
    # 네이버증권API인 요약 정보 기능을 사용 합니다.
    url = f"https://api.finance.naver.com/service/itemSummary.nhn?itemcode={item_code}"
    # requests 패키지를 사용하여 요청을 보냅니다.
    response = requests.get(url)
    # 추후, 데이터 가공을 위해 json 형식으로 변경 합니다.
    json_data = response.json()
    # PER과 PBR을 변수로 지정합니다.
    per_value = json_data['per']
    pbr_value = json_data['pbr']
    # 우선, PER 값이 있는 종목을 골라 냅니다.
    if per_value:
        # PER이 0보다 크고 2보다 작은 종목이면서 PBR이 0.7보다 작은 종목을 찾습니다.
        if 0 < per_value < 2 and 0.7 > pbr_value:
            return f"[{item_name}]의 per은 {per_value} 입니다. (pbr {pbr_value})"
    return None

# func 함수를 stock_list 범위로 병렬 처리 합니다.
if __name__ == '__main__':
    with ThreadPoolExecutor(max_workers=6) as executor:
        results = list(executor.map(func, stock_list))

    # 결과를 출력합니다.
    for result in results:
        if result:
            print(result)