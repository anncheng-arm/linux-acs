
echo "=================================================================="
echo "This script will copy the necessary files for Kernel module build "
echo "to the present directory"
echo "=================================================================="

if [ $# -ne 2 ];
then
    echo "Give both BSA_ACS (1st argument) and SBSA_ACS PATH (2nd argument) as the arguments to the script"
    return 0
fi

export BSA_ACS_PATH=$1
export SBSA_ACS_PATH=$2
echo -e "BSA ACS_PATH is set to -> \e[93m $BSA_ACS_PATH\e[0m"
echo -e "SBSA ACS_PATH is set to -> \e[93m $SBSA_ACS_PATH\e[0m"

cp -r $BSA_ACS_PATH/val .
cp -r $SBSA_ACS_PATH/test_pool .
