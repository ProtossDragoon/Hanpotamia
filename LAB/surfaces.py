from __init__ import *
import pygame
from pygame import gfxdraw

# pygame 의 구조
# surface 객체 에 그림을 막 그림. 도화지 같은 것임. (draw 등)
# 다 그려 주고, 그걸 screen 객체에 붙임. (blit).
## 이때 blit 의 return 은 rect 객체로, 충돌감지 등에 유용하게 사용됨.
# 붙인 후 screen 객체를 update (update)

class Console():
    def __init__(self, screen):
        screensize = screen.get_size()
        self.screen = screen
        
        #self.consolesize = tuple([int(screensize[0] - screensize[0]*0.2), 
        #                          int(screensize[1] - screensize[1]*0.7)])
        self.consolesize = tuple([480, int(screensize[1])])
        # self.consolexy = (int(screen.get_size()[0]-self.consolesize[0]),
        #                  int(screen.get_size()[1]-self.consolesize[1]))        
        self.consolexy = (int(WINDOW_WIDTH-self.consolesize[0]),
                          int(WINDOW_HEIGHT-self.consolesize[1]))

        self.consolesurface = pygame.Surface(self.consolesize)
        self.consolesurface.fill((70, 70, 70))
        self.rect = self.screen.blit(self.consolesurface, self.consolexy)
        
        self.consolefontsize = 14
        self.consolefont = pygame.font.SysFont("Consolas", self.consolefontsize)
        self.textsurfacepaddingxy = (15,15)
        self.printingdata = [] # printingdata should be a list

    def update(self):
        self.rect = self.screen.blit(self.consolesurface, self.consolexy)
        
        # why do this..?
        # because pygame.font.Font/SysFont().render() does not support multiple line text.
        # newline characters are not rendered.
        if len(self.printingdata) != 0 and type(self.printingdata) is list:
            buffersurface = []
            buffer_text_surface_x = self.consolexy[0]+self.textsurfacepaddingxy[0]
            buffer_text_surface_y = self.consolexy[1]+self.textsurfacepaddingxy[1]
            buffer_text_surface_y_adder = self.consolefontsize + int(self.consolefontsize * 0.2)
            for data in self.printingdata:                
                buffersurface.append(
                    self.consolefont.render(str(data), True, WHITE, None),
                    )

        # why do this 2
        # pygame provides no way to directly draw text on an existing Surface: 
        # instead you must use Font.render() to create an image (Surface) of the text, 
        # then blit this image onto another Surface.
        for i in range(len(buffersurface)):
            self.screen.blit(buffersurface[i], (buffer_text_surface_x, 
                                                buffer_text_surface_y + i * buffer_text_surface_y_adder))

    def insertData(self, data):
        self.newdata = data
        self.printingdata = self.newdata
        self.update()        


class City():
    def __init__(self, screen, areaname, player=0, cityscale=0):
        self.screen = screen
        self.areaname = areaname
        self.citysize = cityscale
        self.color = COLOR[0]
        
        # In order to draw antialiased filled shapes with pygame, use the module gfxdraw
        # "To draw an anti aliased and filled shape, 
        # first use the aa* version of the function, and then use the filled version."
        self.rect = pygame.draw.circle(self.screen, self.color, CITY_LOCATION[self.areaname], CITY_SCALE_LIST[self.citysize])
        gfxdraw.aacircle(self.screen, 
                         CITY_LOCATION[self.areaname][0], CITY_LOCATION[self.areaname][1], 
                         CITY_SCALE_LIST[self.citysize], self.color)
        gfxdraw.filled_circle(self.screen,
                         CITY_LOCATION[self.areaname][0], CITY_LOCATION[self.areaname][1], 
                         CITY_SCALE_LIST[self.citysize], self.color)
        print(CITY_LOCATION[self.areaname][0],  CITY_LOCATION[self.areaname][1],
              CITY_SCALE_LIST[self.citysize], self.color)
        self.update()
        
    def update(self):
        self.rect = pygame.draw.circle(self.screen, self.color, CITY_LOCATION[self.areaname], CITY_SCALE_LIST[self.citysize])
        gfxdraw.aacircle(self.screen, 
                         CITY_LOCATION[self.areaname][0], CITY_LOCATION[self.areaname][1], 
                         CITY_SCALE_LIST[self.citysize], self.color)
        gfxdraw.filled_circle(self.screen,
                         CITY_LOCATION[self.areaname][0], CITY_LOCATION[self.areaname][1], 
                         CITY_SCALE_LIST[self.citysize], self.color)

    def setSettings(self, player, cityscale=0):
        # setplayer function does not update.
        self.color = COLOR[player]
        self.citysize = cityscale
        
    
class BackgroundMap():
    def __init__(self, screen, console_width, img='imgsrc/Seoul.png'):
        screensize = screen.get_size()
        
        self.imagebackground = pygame.Surface((screensize[0]-console_width, screensize[1]))
        self.imagebackground.fill(WHITE)
        self.image = pygame.image.load(img).convert_alpha() # pygame.image.load(img) : return surface
        # self.image = pygame.transform.scale(self.image)
        self.screen = screen
        
        self.city = {}
        cnt = 0
        for key in CITY_LOCATION:
            self.city[key] = City(self.screen, key)
            
        self.update()
    
    def update(self):
        # 한번만 렌더링하고 마려고 했지만, 이건 discription hide 같이,
        # 중복되는 부분은 다시 칠해줘야 잔상이 안남음.
        # 그리는 순서 : image background -> image -> city
        self.screen.blit(self.imagebackground, (0,0))
        self.screen.blit(self.image, (0,0))
        for key in self.city:
            self.city[key].update()
        print('update background and image')        


class Charactor():
    def __init__(self, screen, img):        
        self.image = pygame.image.load(img).convert_alpha() # return : surface
        self.image = pygame.transform.scale(self.image, (35, 35)) # return : surface
        self.screen = screen
                  
    def drawCharactor(self):
        pass

    def update(self, charactorxy):
        self.charactorxy = charactorxy
        self.rect = self.screen.blit(self.image, self.charactorxy)


class Explaination():
    def __init__(self, screen):
        self.screen = screen        
        #self.consolesize = tuple([int(screensize[0] - screensize[0]*0.2), 
        #                          int(screensize[1] - screensize[1]*0.7)])
        self.consolesize = tuple((300, 280))
        # self.consolexy = (int(screen.get_size()[0]-self.consolesize[0]),
        #                  int(screen.get_size()[1]-self.consolesize[1]))        
        self.consolexy = (20, 20)

        self.consolesurface = pygame.Surface(self.consolesize, pygame.SRCALPHA)
        self.consolefontsize = 14
        self.consolefont = pygame.font.SysFont("Consolas", self.consolefontsize)
        self.textsurfacepaddingxy = (15,15)
        self.printingdata = [] # printingdata should be a list
        self.hidesignal = 0

    def update(self, show_or_hide, recovorysurface = None):
        if show_or_hide == 'show':
            self.hidesignal = 1
            self.consolesurface.fill((120, 120, 120))
            self.screen.blit(self.consolesurface, self.consolexy)
            
            if len(self.printingdata) != 0 and type(self.printingdata) is list:
                buffersurface = []
                buffer_text_surface_x = self.consolexy[0]+self.textsurfacepaddingxy[0]
                buffer_text_surface_y = self.consolexy[1]+self.textsurfacepaddingxy[1]
                buffer_text_surface_y_adder = self.consolefontsize + int(self.consolefontsize * 0.2)
                for data in self.printingdata:                
                    buffersurface.append(
                        self.consolefont.render(str(data), True, WHITE, None),
                        )
                
            for i in range(len(buffersurface)):
                self.screen.blit(buffersurface[i], (buffer_text_surface_x, 
                                                    buffer_text_surface_y + i * buffer_text_surface_y_adder))
        
        elif show_or_hide == 'hide':
            # hide console surface just once !            
            if self.hidesignal == 1:
                recovorysurface.update()
                self.hidesignal = 0
            else :
                pass
            
        else :
            print('error! parameter should be show or hide')

    def insertData(self, data):
        self.newdata = data
        self.printingdata = self.newdata

    def showDiscription(self, discription):
        self.insertData(discription)
        self.update('show')
    
    def hideDiscription(self, backgroundsurface):
        self.update('hide', backgroundsurface)
        

class Minimap():
    pass


class Dashboard():
    pass