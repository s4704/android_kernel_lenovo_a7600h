/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*******************************************************************************
 *
 * Filename:
 * ---------
 *   AudioAfe.h
 *
 * Project:
 * --------
 *   MT6583  Audio Driver Afe Register setting
 *
 * Description:
 * ------------
 *   Audio register
 *
 * Author:
 * -------
 * Chipeng Chang
 *
 *------------------------------------------------------------------------------
 * $Revision: #1 $
 * $Modtime:$
 * $Log:$
 *
 *
 *******************************************************************************/

/*****************************************************************************
 *                     C O M P I L E R   F L A G S
 *****************************************************************************/


/*****************************************************************************
 *                E X T E R N A L   R E F E R E N C E S
 *****************************************************************************/

#include "AudDrv_Common.h"
#include "AudDrv_Afe.h"
#include "AudDrv_Clk.h"
#include "AudDrv_Def.h"

/*****************************************************************************
 *                         D A T A   T Y P E S
 *****************************************************************************/



/*****************************************************************************
 *                         FUNCTION DEFINITION
 *****************************************************************************/
void Afe_Set_Reg(uint32 offset, uint32 value, uint32 mask);
uint32 Afe_Get_Reg(uint32 offset);

/*****************************************************************************
 *                         FUNCTION IMPLEMENTATION
 *****************************************************************************/

void Afe_Set_Reg(uint32 offset, uint32 value, uint32 mask)
{
#ifdef AUDIO_MEM_IOREMAP
    extern void *AFE_BASE_ADDRESS;
    //PRINTK_AUDDRV("Afe_Set_Reg AUDIO_MEM_IOREMAP AFE_BASE_ADDRESS = %p\n",AFE_BASE_ADDRESS);
    volatile uint32 address = (uint32)((char *)AFE_BASE_ADDRESS + offset);
#else
    volatile uint32 address = (AFE_BASE + offset);
#endif

    volatile uint32 *AFE_Register = (volatile uint32 *)address;
    volatile uint32 val_tmp;

    //PRINTK_AFE_REG("Afe_Set_Reg offset=%x, value=%x, mask=%x \n",offset,value,mask);
    val_tmp = Afe_Get_Reg(offset);
    val_tmp &= (~mask);
    val_tmp |= (value & mask);
    mt65xx_reg_sync_writel(val_tmp, AFE_Register);
}


uint32 Afe_Get_Reg(uint32 offset)
{
#ifdef AUDIO_MEM_IOREMAP
    extern void *AFE_BASE_ADDRESS;
    //PRINTK_AUDDRV("Afe_Get_Reg AUDIO_MEM_IOREMAP AFE_BASE_ADDRESS = %p\ offset = %xn",AFE_BASE_ADDRESS,offset);
    volatile uint32 address = (uint32)((char *)AFE_BASE_ADDRESS + offset);
#else
    volatile uint32 address = (AFE_BASE + offset);
#endif
    volatile uint32 *value;
    //PRINTK_AFE_REG("Afe_Get_Reg offset=%x address = %x \n",offset,address);
    value = (volatile uint32 *)(address);
    return *value;
}

void Afe_Log_Print(void)
{
	AudDrv_Clk_On();
	pr_warn("+AudDrv Afe_Log_Print\n");
	pr_warn("AUDIOAFE_TOP_CON0  = 0x%x\n", Afe_Get_Reg(AUDIOAFE_TOP_CON0));
	pr_warn("AUDIO_TOP_CON1  = 0x%x\n", Afe_Get_Reg(AUDIO_TOP_CON1));
	pr_warn("AUDIO_TOP_CON2  = 0x%x\n", Afe_Get_Reg(AUDIO_TOP_CON2));
	pr_warn("AUDIO_TOP_CON3  = 0x%x\n", Afe_Get_Reg(AUDIO_TOP_CON3));
	pr_warn("AFE_DAC_CON0  = 0x%x\n", Afe_Get_Reg(AFE_DAC_CON0));
	pr_warn("AFE_DAC_CON1  = 0x%x\n", Afe_Get_Reg(AFE_DAC_CON1));
	pr_warn("AFE_I2S_CON  = 0x%x\n", Afe_Get_Reg(AFE_I2S_CON));
	pr_warn("AFE_DAIBT_CON0  = 0x%x\n", Afe_Get_Reg(AFE_DAIBT_CON0));
	pr_warn("AFE_CONN0  = 0x%x\n", Afe_Get_Reg(AFE_CONN0));
	pr_warn("AFE_CONN1  = 0x%x\n", Afe_Get_Reg(AFE_CONN1));
	pr_warn("AFE_CONN2  = 0x%x\n", Afe_Get_Reg(AFE_CONN2));
	pr_warn("AFE_CONN3  = 0x%x\n", Afe_Get_Reg(AFE_CONN3));
	pr_warn("AFE_CONN4  = 0x%x\n", Afe_Get_Reg(AFE_CONN4));
	pr_warn("AFE_I2S_CON1  = 0x%x\n", Afe_Get_Reg(AFE_I2S_CON1));
	pr_warn("AFE_I2S_CON2  = 0x%x\n", Afe_Get_Reg(AFE_I2S_CON2));
	pr_warn("AFE_MRGIF_CON  = 0x%x\n", Afe_Get_Reg(AFE_MRGIF_CON));

	pr_warn("AFE_DL1_BASE  = 0x%x\n", Afe_Get_Reg(AFE_DL1_BASE));
	pr_warn("AFE_DL1_CUR  = 0x%x\n", Afe_Get_Reg(AFE_DL1_CUR));
	pr_warn("AFE_DL1_END  = 0x%x\n", Afe_Get_Reg(AFE_DL1_END));
	pr_warn("AFE_I2S_CON3  = 0x%x\n", Afe_Get_Reg(AFE_I2S_CON3));

	pr_warn("AFE_DL2_BASE  = 0x%x\n", Afe_Get_Reg(AFE_DL2_BASE));
	pr_warn("AFE_DL2_CUR  = 0x%x\n", Afe_Get_Reg(AFE_DL2_CUR));
	pr_warn("AFE_DL2_END  = 0x%x\n", Afe_Get_Reg(AFE_DL2_END));

	pr_warn("AFE_CONN_24BIT  = 0x%x\n", Afe_Get_Reg(AFE_CONN_24BIT));

	pr_warn("AFE_AWB_BASE  = 0x%x\n", Afe_Get_Reg(AFE_AWB_BASE));
	pr_warn("AFE_AWB_END  = 0x%x\n", Afe_Get_Reg(AFE_AWB_END));
	pr_warn("AFE_AWB_CUR  = 0x%x\n", Afe_Get_Reg(AFE_AWB_CUR));
	pr_warn("AFE_VUL_BASE  = 0x%x\n", Afe_Get_Reg(AFE_VUL_BASE));
	pr_warn("AFE_VUL_END  = 0x%x\n", Afe_Get_Reg(AFE_VUL_END));
	pr_warn("AFE_VUL_CUR  = 0x%x\n", Afe_Get_Reg(AFE_VUL_CUR));
	pr_warn("AFE_DAI_BASE  = 0x%x\n", Afe_Get_Reg(AFE_DAI_BASE));
	pr_warn("AFE_DAI_END  = 0x%x\n", Afe_Get_Reg(AFE_DAI_END));
	pr_warn("AFE_DAI_CUR  = 0x%x\n", Afe_Get_Reg(AFE_DAI_CUR));
	/*pr_warn("AFE_IRQ_CON  = 0x%x\n",Afe_Get_Reg(AFE_IRQ_CON));6-5-8-2 */

	pr_warn("AFE_MEMIF_MON0  = 0x%x\n", Afe_Get_Reg(AFE_MEMIF_MON0));
	pr_warn("AFE_MEMIF_MON1  = 0x%x\n", Afe_Get_Reg(AFE_MEMIF_MON1));
	pr_warn("AFE_MEMIF_MON2  = 0x%x\n", Afe_Get_Reg(AFE_MEMIF_MON2));
	/*pr_warn("AFE_MEMIF_MON3  = 0x%x\n",Afe_Get_Reg(AFE_MEMIF_MON3));6-5-8-2 */
	pr_warn("AFE_MEMIF_MON4  = 0x%x\n", Afe_Get_Reg(AFE_MEMIF_MON4));
	/*pr_warn("AFE_FOC_CON  = 0x%x\n",Afe_Get_Reg(AFE_FOC_CON));6-5-8-2 */
	/*pr_warn("AFE_FOC_CON1  = 0x%x\n",Afe_Get_Reg(AFE_FOC_CON1));6-5-8-2 */
	/*pr_warn("AFE_FOC_CON2  = 0x%x\n",Afe_Get_Reg(AFE_FOC_CON2));6-5-8-2 */
	/*pr_warn("AFE_FOC_CON3  = 0x%x\n",Afe_Get_Reg(AFE_FOC_CON3));6-5-8-2 */
	/*pr_warn("AFE_FOC_CON4  = 0x%x\n",Afe_Get_Reg(AFE_FOC_CON4));6-5-8-2 */
	/*pr_warn("AFE_FOC_CON5  = 0x%x\n",Afe_Get_Reg(AFE_FOC_CON5));6-5-8-2 */
	/*pr_warn("AFE_MON_STEP  = 0x%x\n",Afe_Get_Reg(AFE_MON_STEP));6-5-8-2 */
	pr_warn("AFE_ADDA_DL_SRC2_CON0  = 0x%x\n", Afe_Get_Reg(AFE_ADDA_DL_SRC2_CON0));
	pr_warn("AFE_ADDA_DL_SRC2_CON1  = 0x%x\n", Afe_Get_Reg(AFE_ADDA_DL_SRC2_CON1));
	pr_warn("AFE_ADDA_UL_SRC_CON0  = 0x%x\n", Afe_Get_Reg(AFE_ADDA_UL_SRC_CON0));
	pr_warn("AFE_ADDA_UL_SRC_CON1  = 0x%x\n", Afe_Get_Reg(AFE_ADDA_UL_SRC_CON1));
	pr_warn("AFE_ADDA_TOP_CON0  = 0x%x\n", Afe_Get_Reg(AFE_ADDA_TOP_CON0));
	pr_warn("AFE_ADDA_UL_DL_CON0  = 0x%x\n", Afe_Get_Reg(AFE_ADDA_UL_DL_CON0));
	pr_warn("AFE_ADDA_SRC_DEBUG  = 0x%x\n", Afe_Get_Reg(AFE_ADDA_SRC_DEBUG));
	pr_warn("AFE_ADDA_SRC_DEBUG_MON0  = 0x%x\n", Afe_Get_Reg(AFE_ADDA_SRC_DEBUG_MON0));
	pr_warn("AFE_ADDA_SRC_DEBUG_MON1  = 0x%x\n", Afe_Get_Reg(AFE_ADDA_SRC_DEBUG_MON1));
	pr_warn("AFE_ADDA_NEWIF_CFG0  = 0x%x\n", Afe_Get_Reg(AFE_ADDA_NEWIF_CFG0));
	pr_warn("AFE_ADDA_NEWIF_CFG1  = 0x%x\n", Afe_Get_Reg(AFE_ADDA_NEWIF_CFG1));
	pr_warn("AFE_SIDETONE_DEBUG  = 0x%x\n", Afe_Get_Reg(AFE_SIDETONE_DEBUG));
	pr_warn("AFE_SIDETONE_MON  = 0x%x\n", Afe_Get_Reg(AFE_SIDETONE_MON));
	pr_warn("AFE_SIDETONE_CON0  = 0x%x\n", Afe_Get_Reg(AFE_SIDETONE_CON0));
	pr_warn("AFE_SIDETONE_COEFF  = 0x%x\n", Afe_Get_Reg(AFE_SIDETONE_COEFF));
	pr_warn("AFE_SIDETONE_CON1  = 0x%x\n", Afe_Get_Reg(AFE_SIDETONE_CON1));
	pr_warn("AFE_SIDETONE_GAIN  = 0x%x\n", Afe_Get_Reg(AFE_SIDETONE_GAIN));
	pr_warn("AFE_SGEN_CON0  = 0x%x\n", Afe_Get_Reg(AFE_SGEN_CON0));
	/*pr_warn("AFE_MRG_MON0  = 0x%x\n",Afe_Get_Reg(AFE_MRG_MON0));6-5-8-2 */
	/*pr_warn("AFE_MRG_MON1  = 0x%x\n",Afe_Get_Reg(AFE_MRG_MON1));6-5-8-2 */
	/*pr_warn("AFE_MRG_MON2  = 0x%x\n",Afe_Get_Reg(AFE_MRG_MON2));6-5-8-2 */
	pr_warn("AFE_TOP_CON0  = 0x%x\n", Afe_Get_Reg(AFE_TOP_CON0));
	pr_warn("AFE_PREDIS_CON0  = 0x%x\n", Afe_Get_Reg(AFE_PREDIS_CON0));
	pr_warn("AFE_PREDIS_CON1  = 0x%x\n", Afe_Get_Reg(AFE_PREDIS_CON1));

	pr_warn("AFE_MOD_PCM_BASE  = 0x%x\n", Afe_Get_Reg(AFE_MOD_PCM_BASE));
	pr_warn("AFE_MOD_PCM_END  = 0x%x\n", Afe_Get_Reg(AFE_MOD_PCM_END));
	pr_warn("AFE_MOD_PCM_CUR  = 0x%x\n", Afe_Get_Reg(AFE_MOD_PCM_CUR));
	/*pr_warn("AFE_IRQ_CON  = 0x%x\n",Afe_Get_Reg(AFE_IRQ_CON));6-5-8-2 */
	pr_warn("AFE_IRQ_MCU_CON  = 0x%x\n", Afe_Get_Reg(AFE_IRQ_MCU_CON));
	pr_warn("AFE_IRQ_STATUS  = 0x%x\n", Afe_Get_Reg(AFE_IRQ_STATUS));
	pr_warn("AFE_IRQ_CLR  = 0x%x\n", Afe_Get_Reg(AFE_IRQ_CLR));
	pr_warn("AFE_IRQ_CNT1  = 0x%x\n", Afe_Get_Reg(AFE_IRQ_CNT1));
	pr_warn("AFE_IRQ_CNT2  = 0x%x\n", Afe_Get_Reg(AFE_IRQ_CNT2));
	pr_warn("AFE_IRQ_MON2  = 0x%x\n", Afe_Get_Reg(AFE_IRQ_MON2));
	/*pr_warn("AFE_IRQ_CNT5  = 0x%x\n",Afe_Get_Reg(AFE_IRQ_CNT5));6-5-8-2 */
	pr_warn("AFE_IRQ1_CNT_MON  = 0x%x\n", Afe_Get_Reg(AFE_IRQ1_CNT_MON));
	pr_warn("AFE_IRQ2_CNT_MON  = 0x%x\n", Afe_Get_Reg(AFE_IRQ2_CNT_MON));
	pr_warn("AFE_IRQ1_EN_CNT_MON  = 0x%x\n", Afe_Get_Reg(AFE_IRQ1_EN_CNT_MON));
	/*pr_warn("AFE_IRQ5_MCU_EN_CNT_MON  = 0x%x\n",Afe_Get_Reg(AFE_IRQ5_MCU_EN_CNT_MON));6-5-8-2 */
	pr_warn("AFE_MEMIF_MINLEN  = 0x%x\n", Afe_Get_Reg(AFE_MEMIF_MINLEN));
	pr_warn("AFE_MEMIF_MAXLEN  = 0x%x\n", Afe_Get_Reg(AFE_MEMIF_MAXLEN));
	pr_warn("AFE_MEMIF_PBUF_SIZE  = 0x%x\n", Afe_Get_Reg(AFE_MEMIF_PBUF_SIZE));

	pr_warn("AFE_GAIN1_CON0  = 0x%x\n", Afe_Get_Reg(AFE_GAIN1_CON0));
	pr_warn("AFE_GAIN1_CON1  = 0x%x\n", Afe_Get_Reg(AFE_GAIN1_CON1));
	pr_warn("AFE_GAIN1_CON2  = 0x%x\n", Afe_Get_Reg(AFE_GAIN1_CON2));
	pr_warn("AFE_GAIN1_CON3  = 0x%x\n", Afe_Get_Reg(AFE_GAIN1_CON3));
	pr_warn("AFE_GAIN1_CONN  = 0x%x\n", Afe_Get_Reg(AFE_GAIN1_CONN));
	pr_warn("AFE_GAIN1_CUR  = 0x%x\n", Afe_Get_Reg(AFE_GAIN1_CUR));
	pr_warn("AFE_GAIN2_CON0  = 0x%x\n", Afe_Get_Reg(AFE_GAIN2_CON0));
	pr_warn("AFE_GAIN2_CON1  = 0x%x\n", Afe_Get_Reg(AFE_GAIN2_CON1));
	pr_warn("AFE_GAIN2_CON2  = 0x%x\n", Afe_Get_Reg(AFE_GAIN2_CON2));
	pr_warn("AFE_GAIN2_CON3  = 0x%x\n", Afe_Get_Reg(AFE_GAIN2_CON3));
	pr_warn("AFE_GAIN2_CONN  = 0x%x\n", Afe_Get_Reg(AFE_GAIN2_CONN));
	pr_warn("AFE_GAIN2_CUR  = 0x%x\n", Afe_Get_Reg(AFE_GAIN2_CUR));
	pr_warn("AFE_GAIN2_CONN2  = 0x%x\n", Afe_Get_Reg(AFE_GAIN2_CONN2));


	pr_warn("FPGA_CFG2  = 0x%x\n", Afe_Get_Reg(FPGA_CFG2));
	pr_warn("FPGA_CFG3  = 0x%x\n", Afe_Get_Reg(FPGA_CFG3));
	pr_warn("FPGA_CFG0  = 0x%x\n", Afe_Get_Reg(FPGA_CFG0));
	pr_warn("FPGA_CFG1  = 0x%x\n", Afe_Get_Reg(FPGA_CFG1));
	pr_warn("FPGA_STC  = 0x%x\n", Afe_Get_Reg(FPGA_STC));

	pr_warn("AFE_ASRC_CON0  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON0));
	pr_warn("AFE_ASRC_CON1  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON1));
	pr_warn("AFE_ASRC_CON2  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON2));
	pr_warn("AFE_ASRC_CON3  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON3));
	pr_warn("AFE_ASRC_CON4  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON4));
	pr_warn("AFE_ASRC_CON5  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON5));
	pr_warn("AFE_ASRC_CON6  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON6));
	pr_warn("AFE_ASRC_CON7  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON7));
	pr_warn("AFE_ASRC_CON8  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON8));
	pr_warn("AFE_ASRC_CON9  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON9));
	pr_warn("AFE_ASRC_CON10  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON10));
	pr_warn("AFE_ASRC_CON11  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON11));
	pr_warn("PCM_INTF_CON1  = 0x%x\n", Afe_Get_Reg(PCM_INTF_CON1));
	pr_warn("PCM_INTF_CON2  = 0x%x\n", Afe_Get_Reg(PCM_INTF_CON2));
	pr_warn("PCM2_INTF_CON  = 0x%x\n", Afe_Get_Reg(PCM2_INTF_CON));

	/*6-5-8-2*/


	pr_warn("AFE_ASRC_CON13  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON13));
	pr_warn("AFE_ASRC_CON14  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON14));
	pr_warn("AFE_ASRC_CON15  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON15));
	pr_warn("AFE_ASRC_CON16  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON16));
	pr_warn("AFE_ASRC_CON17  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON17));
	pr_warn("AFE_ASRC_CON18  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON18));
	pr_warn("AFE_ASRC_CON19  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON19));
	pr_warn("AFE_ASRC_CON20  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON20));
	pr_warn("AFE_ASRC_CON21  = 0x%x\n", Afe_Get_Reg(AFE_ASRC_CON21));

	AudDrv_Clk_Off();
	pr_warn("-AudDrv Afe_Log_Print\n");
}



// export symbols for other module using
EXPORT_SYMBOL(Afe_Set_Reg);
EXPORT_SYMBOL(Afe_Get_Reg);
EXPORT_SYMBOL(Afe_Log_Print);


