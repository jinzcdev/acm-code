"""
    Craps赌博游戏
    我们设定玩家开始游戏时有1000元的赌注
    游戏结束的条件是玩家输光所有的赌注

    Version: 0.1
    Author: 骆昊
"""
from random import randint

money = 100
isfirst = True

while money > 0:
    print('当前总资产为: ', money)
    while True:
        debt = int(input('请下注: '))
        if 0 < debt <= money:
            break
        else:
            print('资产不够, 请再次下注: ')
    isfirst = True
    first_num = 0
    cnt = 1
    while True:
        is_win = 0
        num = randint(1, 6) + randint(1, 6)
        print('第%d轮, 掷骰子得: ' % cnt, num)
        cnt += 1
        if isfirst == True:
            first_num = num
            if num == 7 or num == 11:
                is_win = 1
            elif num == 2 or num == 3 or num == 12:
                is_win = -1
            isfirst = False
        else:
            if num == first_num:
                is_win = 1
            elif num == 7:
                is_win = -1
        if is_win != 0:
            if is_win == 1:
                print('玩家胜')
                money += debt
            else:
                print('庄家胜')
                money -= debt
            break
        else:
            print('本轮无结果, 再掷一次')
print('你破产了!')
