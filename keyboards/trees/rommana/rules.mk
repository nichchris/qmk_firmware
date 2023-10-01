# LTO must be disabled for RP2040 builds
LTO_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no

COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes

# MCU = RP2040
# BOOTLOADER = rp2040
WS2812_DRIVER = vendor

# BELOW IS COPY
SERIAL_DRIVER = vendor

# BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite

#SPACE SAVING
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output

AUDIO_SUPPORTED = no        # Audio is not supported
RGB_MATRIX_SUPPORTED = no   # RGB matrix is supported and enabled by default
RGBLIGHT_SUPPORTED = no     # RGB underglow is supported, but not enabled by default
RGB_MATRIX_ENABLE = no      # Enable keyboard RGB matrix functionality
