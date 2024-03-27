# /** @file
# * Copyright (c) 2018-2024, Arm Limited or its affiliates. All rights reserved.
# * SPDX-License-Identifier : Apache-2.0
#
# * Licensed under the Apache License, Version 2.0 (the "License");
# * you may not use this file except in compliance with the License.
# * You may obtain a copy of the License at
# *
# *  http://www.apache.org/licenses/LICENSE-2.0
# *
# * Unless required by applicable law or agreed to in writing, software
# * distributed under the License is distributed on an "AS IS" BASIS,
# * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# * See the License for the specific language governing permissions and
# * limitations under the License.
# **/

#!/bin/bash

echo "=================================================================="
echo "This script will compile the Linux BSA Kernel module  "
echo "=================================================================="

BSA_ACS_PATH=`pwd`
if [ -z $KERNEL_SRC ]
then
    echo "Error: set KERNEL_SRC path"
    exit 0
fi

if [ $(uname -m) != "aarch64" ] && [ -z $CROSS_COMPILE ]
then
    echo "Error: set CROSS_COMPILE path for cross compile"
    exit 0
fi

cd $BSA_ACS_PATH/platform/pal_linux/files
cp MakefileBSA Makefile
make
cp bsa_acs_pal.o $BSA_ACS_PATH/

cd $BSA_ACS_PATH/val/
cp MakefileBSA Makefile
make
cp bsa_acs_val.o $BSA_ACS_PATH/

cd $BSA_ACS_PATH/test_pool/
make
cp bsa_acs_test.o $BSA_ACS_PATH/

cd $BSA_ACS_PATH/
cp MakefileBSA Makefile
make
