/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

#ifndef BUILD_LK
#include <linux/string.h>
#endif
#include "lcm_drv.h"

#ifdef BUILD_LK
	#include <platform/mt_gpio.h>
	#include <platform/mt_pmic.h>
#elif defined(BUILD_UBOOT)
#else
	#include <mach/mt_gpio.h>
	#include <mach/mt_pm_ldo.h>
	#include <mach/upmu_common.h>
#endif

// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH  (1280) //(800)
#define FRAME_HEIGHT (800) //(1280)

#define LCM_ID_NT35590 (0x90)
// TODO. This LCM ID is NT51012 not 35590.

#define GPIO_LCD_PWR_EN      GPIO118 //GPIO137
#define GPIO_BL_CTRL_EN      GPIO18 //GPIO137
//#define GPIO_LCD_BL_EN       GPIO129
#define HX8896A03 (1)   // main source
#define NT71397 (0)     // second source
// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))

#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))


// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	        lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)										lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)					lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)											lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)   				lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)


#define   LCM_DSI_CMD_MODE							0

static void lcd_power_en(unsigned char enabled)
{
    if(enabled)
    {
	#ifdef BUILD_LK
        /* VMCH1 3.3V */
       // pmic_config_interface(DIGLDO_CON26, 0x01, PMIC_RG_VMCH1_VOSEL_MASK, PMIC_RG_VMCH1_VOSEL_SHIFT);
       // pmic_config_interface(DIGLDO_CON5, 0x1, PMIC_RG_VMCH1_EN_MASK, PMIC_RG_VMCH1_EN_SHIFT);
//VRF28-2
#if 0
	pmic_config_interface( (U32)(ANALDO_CON13),
                             (U32)(0x01),
                             (U32)(PMIC_RG_VRF28_2_EN_MASK),
                             (U32)(PMIC_RG_VRF28_2_EN_SHIFT)
	                         );
	pmic_config_interface( (U32)(ANALDO_CON12),
                             (U32)(0),
                             (U32)(PMIC_RG_VRF28_2_VOSEL_MASK),
                             (U32)(PMIC_RG_VRF28_2_VOSEL_SHIFT)
	                         );

#endif
	#else
        //hwPowerOn(MT65XX_POWER_LDO_VRF28_2, VOL_1800, "LCM");
#endif

	mt_set_gpio_mode(GPIO_LCM_PWR, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO_LCM_PWR, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_LCM_PWR, GPIO_OUT_ONE);
	//MDELAY(120);

    //  mt_set_gpio_mode(GPIO_LCD_BL_EN, GPIO_MODE_00);
    //  mt_set_gpio_dir(GPIO_LCD_BL_EN, GPIO_DIR_OUT);
   //   mt_set_gpio_out(GPIO_LCD_BL_EN, GPIO_OUT_ONE);
    }
    else
    {
    //  mt_set_gpio_mode(GPIO_LCD_BL_EN, GPIO_MODE_00);
    //  mt_set_gpio_dir(GPIO_LCD_BL_EN, GPIO_DIR_OUT);
    //  mt_set_gpio_out(GPIO_LCD_BL_EN, GPIO_OUT_ZERO);
	//MDELAY(120);
	mt_set_gpio_mode(GPIO_LCM_PWR, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO_LCM_PWR, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_LCM_PWR, GPIO_OUT_ZERO);


#ifdef BUILD_LK
        /* VMCH1 3.3V */
        //pmic_config_interface(DIGLDO_CON26, 0x0, PMIC_RG_VMCH1_VOSEL_MASK, PMIC_RG_VMCH1_VOSEL_SHIFT);
 //VRF28
#if 0
pmic_config_interface( (U32)(ANALDO_CON12),
                             (U32)(0),
                             (U32)(PMIC_RG_VRF28_2_VOSEL_MASK),
                             (U32)(PMIC_RG_VRF28_2_VOSEL_SHIFT)
	                         );

       pmic_config_interface( (U32)(ANALDO_CON13),
                             (U32)(0x0),
                             (U32)(PMIC_RG_VRF28_2_EN_MASK),
                             (U32)(PMIC_RG_VRF28_2_EN_SHIFT)
                                 );
#endif
	       //pmic_config_interface(DIGLDO_CON5, 0x0, PMIC_RG_VMCH1_EN_MASK, PMIC_RG_VMCH1_EN_SHIFT);
#else
        //hwPowerDown(MT65XX_POWER_LDO_VRF28_2, "LCM");
#endif

    }
}
#if 0
static void lcd_reset(unsigned char enabled)
{
    if(enabled)
    {
	mt_set_gpio_mode(GPIO_LCD_RST_EN, GPIO_MODE_00);
        mt_set_gpio_dir(GPIO_LCD_RST_EN, GPIO_DIR_OUT);
        mt_set_gpio_out(GPIO_LCD_RST_EN, GPIO_OUT_ONE);
    }
    else
    {
        mt_set_gpio_mode(GPIO_LCD_RST_EN, GPIO_MODE_00);
        mt_set_gpio_dir(GPIO_LCD_RST_EN, GPIO_DIR_OUT);
        mt_set_gpio_out(GPIO_LCD_RST_EN, GPIO_OUT_ZERO);
    }
}
#endif
static void init_lcm_registers(void)
{
#if 0
	unsigned int data_array[16];

#if 1


	data_array[0] = 0x00011500;  //software reset
	dsi_set_cmdq(data_array, 1, 1);

	MDELAY(20);

	data_array[0]=0x0bae1500;
	data_array[1]=0xeaee1500;
	data_array[2]=0x5fef1500;
	data_array[3]=0x68f21500;
	data_array[4]=0x00ee1500;
	data_array[5]=0x00ef1500;
	dsi_set_cmdq(&data_array, 6, 1);

#if 0

	data_array[0] = 0x7DB21500;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x0BAE1500;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x18B61500;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0xEAEE1500;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x5FEF1500;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x68F21500;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00EE1500;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00EF1500;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x64D21500;
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0] = 0x00101500;  //sleep out
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(20);
#endif

	//data_array[0] = 0xEFB11500;
	//dsi_set_cmdq(data_array, 1, 1);
	//MDELAY(1);

	//data_array[0] = 0x00290500;  //display on
	//dsi_set_cmdq(data_array, 1, 1);
#endif

#if 0
	data_array[0] = 0x00010500;  //software reset
	dsi_set_cmdq(data_array, 1, 1);

	MDELAY(20);

	data_array[0] = 0x00023902;
	data_array[1] = 0x00000BAE;
	dsi_set_cmdq(data_array, 2, 1);
	MDELAY(1);

	data_array[0] = 0x00023902;
	data_array[1] = 0x0000EAEE;
	dsi_set_cmdq(data_array, 2, 1);
	MDELAY(1);

	data_array[0] = 0x00023902;
	data_array[1] = 0x00005FEF;
	dsi_set_cmdq(data_array, 2, 1);
	MDELAY(1);

	data_array[0] = 0x00023902;
	data_array[1] = 0x000068F2;
	dsi_set_cmdq(data_array, 2, 1);
	MDELAY(1);

	data_array[0] = 0x00023902;
	data_array[1] = 0x000000EE;
	dsi_set_cmdq(data_array, 2, 1);
	MDELAY(1);

	data_array[0] = 0x00023902;
	data_array[1] = 0x000000EF;
	dsi_set_cmdq(data_array, 2, 1);
	MDELAY(1);

	data_array[0] = 0x00100500;  //sleep out
	dsi_set_cmdq(data_array, 1, 1);
	MDELAY(20);

	data_array[0] = 0x00290500;  //display on
	dsi_set_cmdq(data_array, 1, 1);
#endif
	//MDELAY(5);
#endif
}

static void lcd_backlight_en(unsigned char enabled)
{
	 if(enabled){
	    mt_set_gpio_mode(GPIO_BL_CTRL, GPIO_MODE_00);
      mt_set_gpio_dir(GPIO_BL_CTRL, GPIO_DIR_OUT);
      mt_set_gpio_out(GPIO_BL_CTRL, GPIO_OUT_ONE);
	 }else {
	    mt_set_gpio_mode(GPIO_BL_CTRL, GPIO_MODE_00);
      mt_set_gpio_dir(GPIO_BL_CTRL, GPIO_DIR_OUT);
      mt_set_gpio_out(GPIO_BL_CTRL, GPIO_OUT_ZERO);
	 }

}

static int getLCMID() {
	 int lcm_id = 0;
	 mt_set_gpio_mode(GPIO_LCMID, GPIO_LCMID_M_GPIO);
   mt_set_gpio_dir(GPIO_LCMID, GPIO_DIR_IN);
   mt_set_gpio_pull_enable(GPIO_LCMID, GPIO_PULL_DISABLE);
	 //mt_set_gpio_pull_select(GPIO_LCMID, GPIO_PULL_UP);
   lcm_id = mt_get_gpio_in(GPIO_LCMID);
   return lcm_id;
}

// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
    memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}


static void lcm_get_params(LCM_PARAMS *params)
{

		memset(params, 0, sizeof(LCM_PARAMS));

		params->type   = LCM_TYPE_DSI;

		params->width  = FRAME_WIDTH;
		params->height = FRAME_HEIGHT;

#if 0
		// enable tearing-free
		params->dbi.te_mode 				= LCM_DBI_TE_MODE_VSYNC_ONLY;
		params->dbi.te_edge_polarity		= LCM_POLARITY_RISING;
#endif

        #if (LCM_DSI_CMD_MODE)
		params->dsi.mode   = CMD_MODE;
        #else
		params->dsi.mode   = SYNC_EVENT_VDO_MODE;
        #endif

		// DSI
		/* Command mode setting */
		//1 Three lane or Four lane
		params->dsi.LANE_NUM				= LCM_FOUR_LANE;
		//The following defined the fomat for data coming from LCD engine.
		params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
		params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
		params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
		params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

		// Highly depends on LCD driver capability.
		// Not support in MT6573
		params->dsi.packet_size=256;

		// Video mode setting
		params->dsi.intermediat_buffer_num = 0;//because DSI/DPI HW design change, this parameters should be 0 when video mode in MT658X; or memory leakage

		params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;
		params->dsi.word_count=720*3;


		params->dsi.vertical_sync_active				= 4; //1;
		params->dsi.vertical_backporch					= 8;
		params->dsi.vertical_frontporch					= 4; //10;
		params->dsi.vertical_active_line				= FRAME_HEIGHT;

		params->dsi.horizontal_sync_active				= 32;//5; //1;
		params->dsi.horizontal_backporch				= 21; //57;
		params->dsi.horizontal_frontporch				= 147; //32;
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;

		// Bit rate calculationLCM_DSI_6589_PLL_CLOCK_234
		//1 Every lane speed
		//params->dsi.pll_div1=0;		// div1=0,1,2,3;div1_real=1,2,4,4 ----0: 546Mbps  1:273Mbps
		//params->dsi.pll_div2=1;		// div2=0,1,2,3;div1_real=1,2,4,4
		//params->dsi.fbk_div =31;    // fref=26MHz, fvco=fref*(fbk_div+1)*2/(div1_real*div2_real)
		//params->dsi.PLL_CLOCK = LCM_DSI_6589_PLL_CLOCK_494; //LCM_DSI_6589_PLL_CLOCK_208;
		//params->dsi.PLL_CLOCK = LCM_DSI_6589_PLL_CLOCK_279_5; //LCM_DSI_6589_PLL_CLOCK_208;
		//params->dsi.PLL_CLOCK = LCM_DSI_6589_PLL_CLOCK_227_5; //LCM_DSI_6589_PLL_CLOCK_208;
		params->dsi.PLL_CLOCK = 225; //LCM_DSI_6589_PLL_CLOCK_234; //LCM_DSI_6589_PLL_CLOCK_208;

		//params->dsi.CLK_ZERO = 47;
		//params->dsi.HS_ZERO = 36;

}

static void lcm_init(void)
{
	unsigned int data_array[16];
	#ifdef BUILD_LK
	  printf("[LK/LCM] nt71937 lcm_init() enter\n");
	  //return;//LK donothing
	#else
	  printk("[Kernel/LCM] nt71937 lcm_init() enter\n");
	#endif
    //lcd_reset(0);
    //lcd_power_en(0);
	 //MDELAY(5);
    lcd_power_en(1);
    //MDELAY(50);//Must > 5ms
    // lcd_reset(1);
    /*Sleep Out*/
    //data_array[0] = 0x00110500;
    //dsi_set_cmdq(data_array, 1, 1);
    //MDELAY(8);
    /*Display ON*/
	  //data_array[0] = 0x00290500;
    //dsi_set_cmdq(data_array, 1, 1);
    //MDELAY(8);
    /*Turn ON*/
    MDELAY(25);
	  data_array[0] = 0x00003200;
    dsi_set_cmdq(data_array, 1, 1);
    //MDELAY(10);
    //MDELAY(210);//Must > 50ms
    lcd_backlight_en(1);

	//#endif
}



static void lcm_suspend(void)
{
	unsigned int data_array[16];
	//
	//unsigned int data_array[16];

	//data_array[0]=0x00280500; // Display Off
	//dsi_set_cmdq(data_array, 1, 1);
	//MDELAY(20);

	//data_array[0] = 0x00111500; // Sleep In
	//dsi_set_cmdq(data_array, 1, 1);
  #ifdef BUILD_LK
	  printf("[LK/LCM] lcm_suspend() enter++\n");
	#else
	  printk("[LCM] lcm_suspend()++\n");
	#endif
	lcd_backlight_en(0);
	MDELAY(10);
  //MDELAY(260);
  //lcd_reset(0);
  /*display off 0x28*/
  //data_array[0] = 0x00280500;
  //dsi_set_cmdq(data_array, 1, 1);
  //MDELAY(30);
  /* Sleep Mode On*/
  //data_array[0] = 0x00100500;
  //dsi_set_cmdq(data_array, 1, 1);

  lcd_power_en(0);
  //MDELAY(300);
  #ifdef BUILD_LK
	  printf("[LK/LCM] lcm_suspend() exit--\n");
	#else
	  printk("[LCM] lcm_suspend()--\n");
	#endif
}


static void lcm_resume(void)
{
	  #ifdef BUILD_LK
	    printf("[LK/LCM] lcm_resume() enter++\n");
	    //return;//LK donothing
	  #else
	    printk("[LCM] lcm_resume()++\n");
	  #endif
	  unsigned int data_array[16];
    //lcd_reset(0);
    //lcd_power_en(0);
	  //MDELAY(5);
    lcd_power_en(1);
    //MDELAY(50);//Must > 5ms
   // lcd_reset(1);
    /*Sleep Out*/
    //data_array[0] = 0x00110500;
    //dsi_set_cmdq(data_array, 1, 1);
    //MDELAY(8);
    /*Display ON*/
	  //data_array[0] = 0x00290500;
    //dsi_set_cmdq(data_array, 1, 1);
    //MDELAY(8);
    /*Turn ON*/
    MDELAY(25);
	  data_array[0] = 0x00003200;
    dsi_set_cmdq(data_array, 1, 1);
    //MDELAY(10);
    //MDELAY(260);//Must > 50ms
    //init_lcm_registers();
    lcd_backlight_en(1);
    #ifdef BUILD_LK
	    printf("[LK/LCM] lcm_resume() exit--\n");
	    //return;//LK donothing
	  #else
	    printk("[LCM] lcm_resume()--\n");
	  #endif
}

#if (LCM_DSI_CMD_MODE)
static void lcm_update(unsigned int x, unsigned int y,
                       unsigned int width, unsigned int height)
{
	unsigned int x0 = x;
	unsigned int y0 = y;
	unsigned int x1 = x0 + width - 1;
	unsigned int y1 = y0 + height - 1;

	unsigned char x0_MSB = ((x0>>8)&0xFF);
	unsigned char x0_LSB = (x0&0xFF);
	unsigned char x1_MSB = ((x1>>8)&0xFF);
	unsigned char x1_LSB = (x1&0xFF);
	unsigned char y0_MSB = ((y0>>8)&0xFF);
	unsigned char y0_LSB = (y0&0xFF);
	unsigned char y1_MSB = ((y1>>8)&0xFF);
	unsigned char y1_LSB = (y1&0xFF);

	unsigned int data_array[16];

	data_array[0]= 0x00053902;
	data_array[1]= (x1_MSB<<24)|(x0_LSB<<16)|(x0_MSB<<8)|0x2a;
	data_array[2]= (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0]= 0x00053902;
	data_array[1]= (y1_MSB<<24)|(y0_LSB<<16)|(y0_MSB<<8)|0x2b;
	data_array[2]= (y1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0]= 0x00290508; //HW bug, so need send one HS packet
	dsi_set_cmdq(data_array, 1, 1);

	data_array[0]= 0x002c3909;
	dsi_set_cmdq(data_array, 1, 0);

}
#endif

static unsigned int lcm_compare_id(void)
{
	/*
	unsigned int id=0;
	unsigned char buffer[2];
	unsigned int array[16];

	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(1);

	SET_RESET_PIN(1);
	MDELAY(20);

	array[0] = 0x00023700;// read id return two byte,version and id
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0xF4, buffer, 2);
	id = buffer[0]; //we only need ID
    #ifdef BUILD_LK
		printf("%s, LK nt35590 debug: nt35590 id = 0x%08x\n", __func__, id);
    #else
		printk("%s, kernel nt35590 horse debug: nt35590 id = 0x%08x\n", __func__, id);
    #endif

    if(id == LCM_ID_NT35590)
	return 1;
    else
        return 0;
   */
   #ifdef BUILD_LK
        int LCM_ID = 0;
        LCM_ID = getLCMID();
        if(LCM_ID == NT71397){
            printf("%s, LK selected NT71397 \n", __func__);
            printf("[LK/LCM] lcm_compare_id selected NT71397 devices\n");
            return 1;
        }else {
	          printf("%s, LK selected HX8896A03 \n", __func__);
	          printf("[LK/LCM] lcm_compare_id selected HX8896A03 devices\n");
	          return 0;
        }
   #else
       return 0;
   #endif
}


LCM_DRIVER nt71397_dsi_vdo_lcm_drv =
{
    .name			= "nt71397_dsi_vdo",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	.compare_id     = lcm_compare_id,
#if (LCM_DSI_CMD_MODE)
    .update         = lcm_update,
#endif
    };
