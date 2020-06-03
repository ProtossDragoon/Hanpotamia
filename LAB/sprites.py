from __init__ import *
import pygame
from pygame import gfxdraw


    # pygame.sprite.Group.draw
    # --- blit the Sprite images
    
    # pygame.sprite.Group.clear
    # --- draw a background over the Sprites

class Dashboard():
    def __init__(self, charactor_x, charactor_between_name_margin, name_between_text_margin):
        self.charx = charactor_x
        self.namex = self.charx + charactor_between_name_margin
        self.textx = self.namex + name_between_text_margin

class DashboardPlayerImage(pygame.sprite.Sprite):
 
    def __init__(self, position, image):
        pygame.sprite.Sprite.__init__(self)
        self.user_image_dead = None
        self.user_image_normal = pygame.image.load(image)
        self.user_position = position
 
        self.image = self.user_image_normal
        self.rect = self.image.get_rect()
        self.rect.center = self.user_position
    
class DashboardPlayerName(pygame.sprite.Sprite):

    def __init__(self, text, textstartposition, color):
        pygame.sprite.Sprite.__init__(self)
        self.consolefont = pygame.font.SysFont("Consolas", 14)
        self.image = self.consolefont.render(text, 1, color)

        self.w = self.image.get_width()
        self.h = self.image.get_height()
        self.rect = self.image.get_rect()
        self.rect.center = (textstartposition[0] + self.w//2, textstartposition[1] + self.h//2)