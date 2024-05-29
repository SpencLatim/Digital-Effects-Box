################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Biocfg.cmd: ../Bio.tcf
	@echo 'Building file: $<'
	@echo 'Invoking: TConf'
	"C:/ti/bios_5_42_01_09/xdctools/tconf" -b -Dconfig.importPath="C:/ti/bios_5_42_01_09/packages;" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Biocfg.s??: | Biocfg.cmd
Biocfg_c.c: | Biocfg.cmd
Biocfg.h: | Biocfg.cmd
Biocfg.h??: | Biocfg.cmd
Bio.cdb: | Biocfg.cmd

Biocfg.obj: ./Biocfg.s?? $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="Biocfg.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Biocfg_c.obj: ./Biocfg_c.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="Biocfg_c.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Conversion.obj: ../Conversion.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="Conversion.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Effects.obj: ../Effects.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="Effects.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

FIR.obj: ../FIR.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -O3 -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="FIR.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Inits.obj: ../Inits.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="Inits.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

NCO.obj: ../NCO.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="NCO.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

aic3204.obj: ../aic3204.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="aic3204.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5535.obj: ../ezdsp5535.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="ezdsp5535.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5535_gpio.obj: ../ezdsp5535_gpio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="ezdsp5535_gpio.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5535_i2c.obj: ../ezdsp5535_i2c.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="ezdsp5535_i2c.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5535_i2s.obj: ../ezdsp5535_i2s.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="ezdsp5535_i2s.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5535_led.obj: ../ezdsp5535_led.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="ezdsp5535_led.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5535_sar.obj: ../ezdsp5535_sar.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="ezdsp5535_sar.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ezdsp5535_uart.obj: ../ezdsp5535_uart.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="ezdsp5535_uart.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=large -g --include_path="C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/inc" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/lib" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/include" --include_path="C:/Users/bacon/OneDrive/c55xx_csl/inc" --include_path="C:/Users/bacon/include" --include_path="C:/Users/Spencer/OneDrive/workspace_v6_1/Capstone/Debug" --include_path="C:/ti/bios_5_42_01_09/packages/ti/bios/include" --include_path="C:/ti/bios_5_42_01_09/packages/ti/rtdx/include/c5500" --define=c5535 --display_error_number --diag_warning=225 --ptrdiff_size=16 --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


