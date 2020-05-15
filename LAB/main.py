import time
import random

from __init__ import *

from surfaces import Console, BackgroundMap, Charactor, Minimap, Dashboard, Explaination, City
from pygame.locals import *
import pygame


if __name__ == '__main__' :
    
    pygame.init()
    pygame.font.init()
    clock = pygame.time.Clock()
    
    screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT), 0, 32)
    pygame.display.set_caption('Hanpotamia')
    programIcon = pygame.image.load('imgsrc/worrior_color/worrior_red.png')
    pygame.display.set_icon(programIcon)
    
    console = Console(screen)
    background_surface = BackgroundMap(screen, console.consolesize[0])
    worrior1 = Charactor(screen, 'imgsrc/worrior_color/worrior_red.png')
    areaexplain = Explaination(screen)
    
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
        worrior1.update()


        flag = 0
        for areaname in background_surface.city :
            print(areaname)
            if background_surface.city[areaname].rect.collidepoint(pygame.mouse.get_pos()):
                areaexplain.showDiscription([areaname])
                flag = 1
        if flag == 0 :
            print('hide discription')
            areaexplain.hideDiscription(background_surface)       
        
        # system
        pygame.display.update() # update entire window screen
        i+=1
        
    pygame.quit()   

# Seoul image reference : https://m.blog.naver.com/batt7424/220651741817