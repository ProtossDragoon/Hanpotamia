from __init__ import *
import pygame
from pygame import gfxdraw

class BlockSprite(pygame.sprite.Sprite):
 
    def __init__(self, position, image):
        pygame.sprite.Sprite.__init__(self)
        self.user_image_dead = None
        self.user_image_normal = pygame.image.load(image)
        self.user_position = position
 
        self.image = self.user_image_normal
        self.rect = self.image.get_rect()
        self.rect.center = self.user_position
 
    def update(self, hit_list):
        
        if self in hit_list:
            self.image = self.user_image_hit
        else:
            self.image = self.user_image_normal
 
        self.rect = self.image.get_rect()
        self.rect.center = self.user_position
