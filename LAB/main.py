import time
import random

from __init__ import *

from surfaces import Console, BackgroundMap, Charactor, Minimap, Dashboard, Explaination, City
from sprites import BlockSprite

from pygame.locals import *
import pygame


if __name__ == '__main__' :
    
    players = ['me', 'you']
    
    pygame.init()
    pygame.font.init()
    clock = pygame.time.Clock()
    
    screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT), 0, 32)
    pygame.display.set_caption('Hanpotamia')
    programIcon = pygame.image.load('imgsrc/worrior_color/worrior_red.png')
    pygame.display.set_icon(programIcon)
    
    console = Console(screen)
    background_surface = BackgroundMap(screen, console.consolesize[0])

    charactor_block_list = []
    if len(players) >= 2:
        # worrior1 = Charactor(screen, )
        # worrior2 = Charactor(screen, 'imgsrc/worrior_color/worrior_blue.png')
        worrior1 = BlockSprite((50,50), 'imgsrc/worrior_color/worrior_red.png')
        worrior2 = BlockSprite((50,100), 'imgsrc/worrior_color/worrior_blue.png')
        charactor_block_list.append(worrior1)
        charactor_block_list.append(worrior2)        
    if len(players) >= 3:
        # worrior3 = Charactor(screen, 'imgsrc/worrior_color/worrior_green.png')
        worrior3 = BlockSprite((50,50), 'imgsrc/worrior_color/worrior_green.png')
        charactor_block_list.append(worrior3)
    if len(players) >= 4:
        # worrior4 = Charactor(screen, 'imgsrc/worrior_color/worrior_pink.png')
        worrior4 = BlockSprite((50,50), 'imgsrc/worrior_color/worrior_pink.png')
        charactor_block_list.append(worrior4)
    
    charactor_block_group = pygame.sprite.RenderPlain(*blocks)
 
    
    areaexplain = Explaination(screen)
    
    run = True
    i = 0
 
    while run :
        
        ################################################
        #                user area                     #
        ################################################
        
        clock.tick(20) # Max FPS
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

        
        console.insertData(['data', i]) # insert data and update console screen
#        worrior1.update((50,50))
#        worrior2.update((50,100))


        flag = 0
        for areaname in background_surface.city :
            print(areaname)
            if background_surface.city[areaname].rect.collidepoint(pygame.mouse.get_pos()):
                areaexplain.showDiscription([areaname + '-gu','','hello~ lololol'])
                flag = 1
        if flag == 0 :
            print('don\'t show discription')
            areaexplain.hideDiscription(background_surface)       
        
        # system
        pygame.display.update() # update entire window screen
        i+=1
        
    pygame.quit()   






# Seoul image reference : https://m.blog.naver.com/batt7424/220651741817