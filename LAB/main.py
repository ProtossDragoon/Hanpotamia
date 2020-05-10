import sys
import time
import random

from pygame.locals import *
import pygame

WINDOW_WIDTH = 1080 + 480
WINDOW_HEIGHT = 720
GRID_SIZE = 20
GRID_WIDTH = WINDOW_WIDTH / GRID_SIZE
GRID_HEIGHT = WINDOW_HEIGHT / GRID_SIZE

WHITE = (255, 255, 255)
GREEN = (0, 50, 0)

UP = (0, -1)
DOWN = (0, 1)
LEFT = (-1, 0)
RIGHT = (1, 0)

class Unit(object) :
    def __init__(self):
        self.create()
        self.color = GREEN
    
    def create(self) :
        self.length = 2
        self.positions = [(WINDOW_WIDTH/2), (WINDOW_HEIGHT/2)]
        self.direction = random.choice([UP, DOWN, LEFT, RIGHT])

# pygame 의 구조
# surface 객체 에 그림을 막 그림. 도화지 같은 것임. (draw 등)
# 다 그려 주고, 그걸 screen 객체에 붙임. (blit)
# 붙인 후 screen 객체를 update (update)

class Console(pygame.Surface):
    def __init__(self, screen):
        screensize = screen.get_size()
        print("WIDTH : ", screensize[0])
        print("HEIGHT : ", screensize[1])
        self.screen = screen
        #self.consolesize = tuple([int(screensize[0] - screensize[0]*0.2), 
        #                          int(screensize[1] - screensize[1]*0.7)])
        self.consolesize = tuple([480, int(screensize[1])])
        print(self.consolesize)
        self.consolesurface = pygame.Surface(self.consolesize)
        self.consolesurface.fill((70, 70, 70))
        self.consolefont = pygame.font.SysFont('Comic Sans MS', 14)
        self.textsurfacepaddingxy = (15,15)
    
    def insertData(self, data):
        self.newdata = data
        self.printingdata = 'none'
        self.update(screen)        

    def update(self, screen):
        # self.consolexy = (int(screen.get_size()[0]-self.consolesize[0]),
        #                  int(screen.get_size()[1]-self.consolesize[1]))
        self.consolexy = (int(WINDOW_WIDTH-self.consolesize[0]),
                          int(WINDOW_HEIGHT-self.consolesize[1]))
        print(self.consolexy)
        screen.blit(self.consolesurface, self.consolexy)
        self.consolesurface = self.consolesurface.convert_alpha()
        self.consoletextsurface = self.consolefont.render(self.printingdata, False, WHITE, None)
        # pygame provides no way to directly draw text on an existing Surface: 
        # instead you must use Font.render() to create an image (Surface) of the text, 
        # then blit this image onto another Surface.
            
        screen.blit(self.consoletextsurface, (self.consolexy[0]+self.textsurfacepaddingxy[0],
                                              self.consolexy[1]+self.textsurfacepaddingxy[1]))
        
        pygame.display.update()

class Minimap(pygame.Surface):
    pass

class Dashboard(pygame.Surface):
    pass


class BackgroundMap(pygame.Surface):
    def __init__(self, screen, img='imgsrc/Seoul.png'):
        self.imagebackground = pygame.Surface(screen.get_size())
        self.imagebackground.fill(WHITE)
        self.image = pygame.image.load(img).convert_alpha()
        # self.image = pygame.transform.scale(self.image)
        self.screen = screen
        self.update()
    
    def update(self):
        self.screen.blit(self.imagebackground, (0,0))
        self.screen.blit(self.image, (0,0))
        pygame.display.update()        


class Charactor(pygame.Surface):
    def __init__(self, screen, img):        
        self.image = pygame.image.load(img).convert_alpha()
        self.image = pygame.transform.scale(self.image, (35, 35))
        self.screen = screen
        self.charactorboundingrect = self.image.get_rect()
                  
    def drawCharactor(self):
        pass

    def update(self):
        self.charactorxy = (50, 50)
        screen.blit(self.image, self.charactorxy)
        pygame.display.update()

            
if __name__ == '__main__' :
    
    pygame.init()
    pygame.font.init()
    clock = pygame.time.Clock()
    
    screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT), 0, 32)
    pygame.display.set_caption('Hanpotamia')
    
    
    background_surface = BackgroundMap(screen)
    console = Console(screen)
    worrior1 = Charactor(screen, 'imgsrc/worrior_color/worrior_red.png')
        
    run = True
    while run :
        clock.tick(10) # Max 60 FPS
                
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

        worrior1.update()
        console.insertData({'data' : 'temp data'}) # insert data and update console screen
        pygame.display.update() # update entire window screen
        
    pygame.quit()




    

# Seoul image reference : https://m.blog.naver.com/batt7424/220651741817