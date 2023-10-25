
# System Architecture Compliance Suite - Linux Kernel module

The present revision of this repository hosts the kernel code required to run some of the tests of following Arm Architecture Compliance suite:

## SBSA-ACS:

Some of the SBSA tests are executed by running the SBSA ACS Linux application which in turn depends on the SBSA ACS Linux kernel module.
SBSA kernel module have dependency on Linux Platform APIs and a kernel patch file available in this repository.

While Building the SBSA ACS Linux Application and Kernel Module for a particular tag, Please use the Linux version and Linux ACS Tag as mentioned in the table below.

| SBSA ACS Tag ID | Linux Version |  Linux ACS Tag ID  |
|-----------------|---------------|--------------------|
|[v23.09_REL7.1.3](https://github.com/ARM-software/sbsa-acs/releases/tag/v23.09_REL7.1.3)   |     v6.4     | [v23.09_SR_REL2.0.0_ES_REL1.3.0_IR_REL2.1.0](https://gitlab.arm.com/linux-arm/linux-acs/-/tags/v23.09_SR_REL2.0.0_ES_REL1.3.0_IR_REL2.1.0) |
|[v22.10_REL6.1.0](https://github.com/ARM-software/sbsa-acs/releases/tag/v22.10_REL6.1.0)   |     v6.0     | [v22.10_REL1.1.0](https://gitlab.arm.com/linux-arm/linux-acs/-/tags/v22.10_REL1.1.0) |
|[v22.02_SR_REL1.0](https://github.com/ARM-software/sbsa-acs/releases/tag/v22.02_SR_REL1.0) |     v5.15    | [v22.02_SR_REL1.0](https://gitlab.arm.com/linux-arm/linux-acs/-/tags/v22.02_SR_REL1.0) |
|[v21.10_REL3.1.1](https://github.com/ARM-software/sbsa-acs/releases/tag/v21.10_REL3.1.1)   |     v5.13    | [v21.09_REL3.1](https://gitlab.arm.com/linux-arm/linux-acs/-/tags/v21.09_REL3.1) |

The steps required to build and run SBSA ACS Linux Tests can be found as part of the [SBSA ACS README file](https://github.com/ARM-software/sbsa-acs/blob/master/README.md).

## BSA-ACS:

Some of the BSA tests are executed by running the BSA ACS Linux application which in turn depends on the BSA ACS Linux kernel module.
BSA kernel module have dependency on Linux Platform APIs and a kernel patch file available in this repository.

While Building the BSA ACS Linux Application and Kernel Module for a particular tag, Please use the Linux version and Linux ACS Tag as mentioned in the table below.


| BSA ACS Tag ID | Linux Version |  Linux ACS Tag ID  |
|----------------|---------------|--------------------|
|[v23.09_REL1.0.6](https://github.com/ARM-software/bsa-acs/releases/tag/v23.09_REL1.0.6) |     v6.4     | [v23.09_SR_REL2.0.0_ES_REL1.3.0_IR_REL2.1.0](https://gitlab.arm.com/linux-arm/linux-acs/-/tags/v23.09_SR_REL2.0.0_ES_REL1.3.0_IR_REL2.1.0) |
|[v22.10_REL1.0.2](https://github.com/ARM-software/bsa-acs/releases/tag/v22.10_REL1.0.2) |     v6.0     | [v22.10_REL1.1.0](https://gitlab.arm.com/linux-arm/linux-acs/-/tags/v22.10_REL1.1.0) |
|[v22.06_REL1.0.1](https://github.com/ARM-software/bsa-acs/releases/tag/v22.06_REL1.0.1) |     v5.15    | [v22.02_SR_REL1.0](https://gitlab.arm.com/linux-arm/linux-acs/-/tags/v22.02_SR_REL1.0) |
|[v21.09_REL1.0](https://github.com/ARM-software/bsa-acs/releases/tag/v21.09_REL1.0)     |     v5.13    | [v21.09_REL3.1](https://gitlab.arm.com/linux-arm/linux-acs/-/tags/v21.09_REL3.1) |

The steps required to build and run BSA ACS Linux Tests can be found as part of the [BSA ACS README file](https://github.com/ARM-software/bsa-acs/blob/main/README.md).

## SDEI-ACS:

The steps required to build and run this code can be found as part of the [SDEI ACS README file](https://github.com/ARM-software/arm-enterprise-acs/tree/master/sdei#readme).

## FF-A-ACS:

The steps required to build and run this code can be found as part of the [ffa-acs-drv/README](./ffa-acs-drv/README.md)

## Maintainer List
- Prasanth Pulla (prasanth.pulla@arm.com)
- Chetan Rathore (Chetan.Rathore@arm.com)
- Rajat Goyal (Rajat.Goyal@arm.com)
