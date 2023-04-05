from random import randint
import time

def enhance_equipment(level):
    fail_rate = (level * 10)
    destroy_rate = 10
    
    gamble = randint(1, 100)
    
    if gamble <= destroy_rate and level > 0:
        return 0, "destroyed"
    elif gamble <= destroy_rate + fail_rate and level > 0:
        return max(0, level - 1), "failed"
    else:
        return min(7, level + 1), "succeeded"

def main():
    level = 0
    game_over = False
    delay = 0.3
    
    print("\n\n==============================")
    print("🗡 장비 강화 시스템을 시작합니다!🗡")
    print("==============================")
    
    ask = input("장비 강화를 하시겠습니까?🐱‍👤 (Y/N 을 입력하세요): ")
    print("==============================")
    
    if ask.lower() == "y":
        while not game_over:
            print("강화 중 입니다...(MAX 7강)")
            time.sleep(delay)
            print("...")
            time.sleep(delay)
            print("...")
            time.sleep(delay)
            print("...")
            
            level, result = enhance_equipment(level)
            
            if result == "destroyed":
                print("==============================")
                print("장비가 파괴되었습니다 ㅠㅠ")
                print("==============================")
                level = 0
            elif result == "failed":
                print("==============================")
                print("강화가 실패했습니다!!!😒")
                print("==============================")
            else:
                print("장비가 강화되었습니다!!!")
                print("==============================")
            
            print("현재 장비의 레벨은 +%d강 입니다." % level)
            print("==============================")
            
            if level == 7:
                print("\n장비가 최대로 강화되었습니다!! 축하합니다🏆 \n")
                time.sleep(3)
                game_over = True
            else:
                ask2 = input("\n\n계속 강화 하시겠습니까?🤭 (Y/N): ")
                if ask2.lower() == "n":
                    print("\n당신은 쫄보입니다😜 \n")
                    time.sleep(3)
                    game_over = True
    else:
        print("\n당신은 쫄보입니다😜 \n")
        time.sleep(3)

if __name__ == "__main__":
    main()
