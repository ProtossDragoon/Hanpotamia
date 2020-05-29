import time
import random

from __init__ import *

from surfaces import Console, BackgroundMap, Charactor, Minimap, Explaination, City
from sprites import Dashboard, DashboardPlayerImage, DashboardPlayerName

from pygame.locals import *
import pygame


if __name__ == '__main__' :
    
    players = ['me', 'you', 'fuckyou', 'hello']
    
    pygame.init()
    pygame.font.init()
    clock = pygame.time.Clock()
    pygame.display.set_caption('Hanpotamia')
    programIcon = pygame.image.load('imgsrc/worrior_color/worrior_red.png')
    pygame.display.set_icon(programIcon)
    
    # 찐텐 배경 관련
    screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT), 0, 32)
        
    # 우측 약간 검은부분 관련
    console = Console(screen)
    
    # 배경 및 city 렌더링 관련
    background_surface = BackgroundMap(screen, console.consolesize[0])

    # 설명창 관련
    areaexplain = Explaination(screen)

    # 대시보드 관련
    charactor_block_list = []
    username_block_list = []
    consolemargin = 0
    dashboardSetting = Dashboard(1080+30, 30, 100)
    if len(players) >= 2:
        worrior1 = DashboardPlayerImage((dashboardSetting.charx,50), 'imgsrc/worrior_color/worrior_red.png')
        worrior2 = DashboardPlayerImage((dashboardSetting.charx,100), 'imgsrc/worrior_color/worrior_blue.png')
        player1name = DashboardPlayerName(players[0], (dashboardSetting.namex, 50), WHITE)
        player2name = DashboardPlayerName(players[1], (dashboardSetting.namex, 100), WHITE)
        charactor_block_list.append(worrior1)
        charactor_block_list.append(worrior2)
        username_block_list.append(player1name)
        username_block_list.append(player2name)
        consolemargin += 100        
    if len(players) >= 3:
        worrior3 = DashboardPlayerImage((dashboardSetting.charx,150), 'imgsrc/worrior_color/worrior_green.png')
        player3name = DashboardPlayerName(players[2], (dashboardSetting.namex, 150), WHITE)
        charactor_block_list.append(worrior3)
        username_block_list.append(player3name)
        consolemargin += 50
    if len(players) >= 4:
        worrior4 = DashboardPlayerImage((dashboardSetting.charx,200), 'imgsrc/worrior_color/worrior_pink.png')
        player4name = DashboardPlayerName(players[3], (dashboardSetting.namex, 200), WHITE)
        charactor_block_list.append(worrior4)
        username_block_list.append(player4name)
        consolemargin += 50
    consolemargin += 10

    console.set_textprinting_topmargin_for_dashboard(consolemargin)
    charactor_block_group = pygame.sprite.RenderPlain(*charactor_block_list)
    username_block_group = pygame.sprite.RenderPlain(*username_block_list)    

    
    run = True
    i = 0
 
    while run :
        
        ################################################
        #                user area                     #
        ################################################
        
        clock.tick(10) # Max FPS
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

        
        console.insertData(['data', i]) # insert data and update console screen
        charactor_block_group.draw(screen)
        username_block_group.draw(screen)

        flag = 0
        for areaname in background_surface.city :
            print(areaname)
            if background_surface.city[areaname].rect.collidepoint(pygame.mouse.get_pos()):
                areaexplain.showDiscription([areaname + '-gu','','hello~ lololol'])
                background_surface.city[areaname].temporaryAttention()
                flag = 1
        if flag == 0 :
            print('don\'t show discription')
            areaexplain.hideDiscription(background_surface)       
        
        # system
        pygame.display.update() # update entire window screen
        i+=1
        
    pygame.quit()   






# Seoul image reference : https://m.blog.naver.com/batt7424/220651741817