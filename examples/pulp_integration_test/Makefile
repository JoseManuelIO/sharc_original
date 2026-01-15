# Makefile for PULP SDK integration test
# This Makefile is compatible with PULP SDK and can compile main.c for GVSoc

APP = dummy_controller

# Application source files
APP_SRCS = main.c

# Application C flags
APP_CFLAGS = -O2 -Wall

# Include PULP SDK build rules
# This assumes PULP_SDK_HOME environment variable is set
include $(PULP_SDK_HOME)/install/rules/pmsis_rules.mk
