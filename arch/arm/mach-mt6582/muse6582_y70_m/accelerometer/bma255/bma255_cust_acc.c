#include <linux/types.h>
#include <cust_acc.h>
#include <mach/mt_pm_ldo.h>


/*---------------------------------------------------------------------------*/
static struct acc_hw cust_acc_hw = {
    .i2c_num    = 2,
    .direction  = 5,                    /*!< If direction is changed, modify it*/
    .power_id   = MT65XX_POWER_NONE,    /*!< LDO is not used */
    .power_vol  = VOL_DEFAULT,          /*!< LDO is not used */
    .firlen = 0,                        /*!< don't enable low pass fileter */
};
/*---------------------------------------------------------------------------*/
struct acc_hw* bma255_get_cust_acc_hw(void)
{
    return &cust_acc_hw;
}
