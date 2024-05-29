################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/c5500_4.4.1

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := -l"./Biocfg.cmd"

ORDERED_OBJS += \
"./Biocfg.obj" \
"./Biocfg_c.obj" \
"./Conversion.obj" \
"./Effects.obj" \
"./FIR.obj" \
"./Inits.obj" \
"./NCO.obj" \
"./aic3204.obj" \
"./ezdsp5535.obj" \
"./ezdsp5535_gpio.obj" \
"./ezdsp5535_i2c.obj" \
"./ezdsp5535_i2s.obj" \
"./ezdsp5535_led.obj" \
"./ezdsp5535_sar.obj" \
"./ezdsp5535_uart.obj" \
"./main.obj" \
$(GEN_CMDS__FLAG) \
-l"libc.a" \
-l"cslVC5505.lib" \
-l"ezdsp5535bsl.lib" \
-l"rts55x.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Capstone.out \

EXE_OUTPUTS__QUOTED += \
"Capstone.out" \

BIN_OUTPUTS += \
Capstone.hex \

BIN_OUTPUTS__QUOTED += \
"Capstone.hex" \


# All Target
all: Capstone.out

# Tool invocations
Capstone.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C5500 Linker'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 -z -m"Capstone.map" --stack_size=0x200 --heap_size=0x400 -i"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/lib" -i"C:/Users/bubak/Desktop/ezdsp5535_v1_spring2024/lib" -i"C:/Users/bacon/OneDrive/c55xx_csl/ccs_v4.0_examples/cslVC5505/Debug" -i"C:/Users/bacon/OneDrive/lib" -i"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" -i"C:/ti/bios_5_42_01_09/packages/ti/rtdx/lib/c5500" -i"C:/ti/bios_5_42_01_09/packages/ti/bios/lib" --reread_libs --display_error_number --warn_sections --xml_link_info="Capstone_linkInfo.xml" --rom_model --sys_stacksize=0x200 -o "Capstone.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

Capstone.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C5500 Hex Utility'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/hex55"  -o "Capstone.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_HDRS__QUOTED)$(GEN_MISC_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_CMDS__QUOTED)
	-$(RM) "Biocfg_c.pp" "Conversion.pp" "Effects.pp" "FIR.pp" "Inits.pp" "NCO.pp" "aic3204.pp" "ezdsp5535.pp" "ezdsp5535_gpio.pp" "ezdsp5535_i2c.pp" "ezdsp5535_i2s.pp" "ezdsp5535_led.pp" "ezdsp5535_sar.pp" "ezdsp5535_uart.pp" "main.pp" 
	-$(RM) "Biocfg.pp" 
	-$(RM) "Biocfg.obj" "Biocfg_c.obj" "Conversion.obj" "Effects.obj" "FIR.obj" "Inits.obj" "NCO.obj" "aic3204.obj" "ezdsp5535.obj" "ezdsp5535_gpio.obj" "ezdsp5535_i2c.obj" "ezdsp5535_i2s.obj" "ezdsp5535_led.obj" "ezdsp5535_sar.obj" "ezdsp5535_uart.obj" "main.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

