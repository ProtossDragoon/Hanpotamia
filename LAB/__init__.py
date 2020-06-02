WINDOW_WIDTH = 1080 + 480
WINDOW_HEIGHT = 720
GRID_SIZE = 20
GRID_WIDTH = WINDOW_WIDTH / GRID_SIZE
GRID_HEIGHT = WINDOW_HEIGHT / GRID_SIZE

WHITE = (255, 255, 255)


BLACK = (0, 0, 0)
RED =  (120, 10, 10)
GREEN = (10, 120, 10)
BLUE = (10, 10, 120)

COLOR = [BLACK, RED, GREEN, BLUE]
CITY_LOCATION = {
    'Dobong' : (666, 85),
    'Nowon' : (764, 148),
    'gangbook' : (616, 173),
    'Seongbuk' : (616, 272),
    'Dongdaemun' : (716,322),
    'Jungnang' : (800,272),
    'Seongdong' : (680,400),
    'Gwangjin' : (789,417),
    'Jongno' : (516,297),
    'Jung' : (566, 372),
    'Yongsan' : (539,450),
    'Eunpyeong' : (439, 198),
    'Seodaemun' : (451, 335),
    'Mapo' : (389, 375),
    'Gangseo' : (196, 372),
    'Yangcheon' : (256, 491),
    'Guro' : (281, 559),
    'Yeongdeungpo' : (389, 500),
    'Dongjak' : (489, 534),
    'Geumcheon' : (374, 651),
    'Gwanak' : (514, 651),
    'Seocho' : (616, 575),
    'Gangnam' : (741, 575),
    'Songpa' : (839, 534),
    'Gangdong' : (912, 417),
}

CITY_SCALE_LIST = [25, 10, 15, 25, 35, 45]
# 25 : default
# 10 : less than 500
# 15 : less than 1000
# 25 : less than 10000
# 35 : less than 100000
# 45 : more than 100000