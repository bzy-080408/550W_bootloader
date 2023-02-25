LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include

OBJS += \
	$(LOCAL_DIR)/tests.o \
	$(LOCAL_DIR)/thread_tests.o \
	$(LOCAL_DIR)/spi_test.o \
	$(LOCAL_DIR)/printf_tests.o

ifeq ($(VERIFIED_BOOT),1)
OBJS += \
	$(LOCAL_DIR)/kauth_test.o
endif
