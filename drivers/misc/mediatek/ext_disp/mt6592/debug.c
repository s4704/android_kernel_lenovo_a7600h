#if defined(CONFIG_MTK_HDMI_SUPPORT)
#include <linux/string.h>
#include <linux/time.h>
#include <linux/uaccess.h>

#include <linux/debugfs.h>

#include <mach/mt_typedefs.h>


#include "hdmi_drv.h"
#include "hdmitx_drv.h"

/*extern int mmp_image_scale;*/

/*
---------------------------------------------------------------------------
  External variable declarations
---------------------------------------------------------------------------

  extern LCM_DRIVER *lcm_drv;
---------------------------------------------------------------------------
  Debug Options
---------------------------------------------------------------------------
*/

static char STR_HELP[] =
	"\n"
	"USAGE\n"
	"echo [ACTION]... > hdmi\n"
	"\n" "ACTION\n"
	"hdmitx:[on|off]\n"
	"enable hdmi video output\n"
	"\n";

static void process_dbg_opt(const char *opt)
{
#if defined(MTK_HDMI_SUPPORT)
	if (0 == strncmp(opt, "on", 2)) {
			hdmi_power_on();
	} else if (0 == strncmp(opt, "off", 3)) {
			hdmi_power_off();
	} else if (0 == strncmp(opt, "suspend", 7)) {
			hdmi_suspend();
	} else if (0 == strncmp(opt, "resume", 6)) {
			hdmi_resume();
	} else if (0 == strncmp(opt, "log:", 4)) {
		if (0 == strncmp(opt + 4, "on", 2))
			hdmi_log_enable(true);
		else if (0 == strncmp(opt + 4, "off", 3))
			hdmi_log_enable(false);
		else
			goto Error;
	} else if (0 == strncmp(opt, "fakecablein:", 12)) {
		if (0 == strncmp(opt + 12, "enable", 6))
			hdmi_cable_fake_plug_in();
		else if (0 == strncmp(opt + 12, "disable", 7))
				hdmi_cable_fake_plug_out();
		else
			goto Error;
	}
#endif
	if (0 == strncmp(opt, "hdmimmp:", 8)) {
		if (0 == strncmp(opt + 8, "on", 2))
			hdmi_mmp_enable(1);
		else if (0 == strncmp(opt + 8, "off", 3))
				hdmi_mmp_enable(0);
		else if (0 == strncmp(opt + 8, "img", 3))
				hdmi_mmp_enable(7);
		else
			goto Error;
	} else if (0 == strncmp(opt, "imgscale:", 9)) {
		char *p = (char *)opt + 9;
		unsigned int level = 0;
		/*unsigned int level = (unsigned int)simple_strtoul(p, &p, 3);*/

		if (level) {
			if (level > 10)
				level = 10;
			if (level < 1)
				level = 1;
			/*mmp_image_scale = level; */
			/*printk("[hdmitx] imgscale set to %d\n", mmp_image_scale); */
		} else {
			goto Error;
		}
	} else {
		goto Error;
	}

	return;
}

static void process_dbg_cmd(char *cmd)
{
	char *tok;

	while ((tok = strsep(&cmd, " ")) != NULL)
		process_dbg_opt(tok);
}

/*
---------------------------------------------------------------------------
    Debug FileSystem Routines
---------------------------------------------------------------------------
*/
struct dentry *hdmitx_dbgfs = NULL;


static ssize_t debug_open(struct inode *inode, struct file *file)
{
	file->private_data = inode->i_private;
	return 0;
}


static char debug_buffer[2048];

static ssize_t debug_read(struct file *file, char __user *ubuf, size_t count, loff_t *ppos)
{
	const int debug_bufmax = sizeof(debug_buffer) - 1;
	int n = 0;

	n += scnprintf(debug_buffer + n, debug_bufmax - n, STR_HELP);
	debug_buffer[n++] = 0;

	return simple_read_from_buffer(ubuf, count, ppos, debug_buffer, n);
}


static ssize_t debug_write(struct file *file, const char __user *ubuf, size_t count, loff_t *ppos)
{
	const int debug_bufmax = sizeof(debug_buffer) - 1;
	size_t ret;

	ret = count;

	if (count > debug_bufmax)
		count = debug_bufmax;

	if (copy_from_user(&debug_buffer, ubuf, count))
		return -EFAULT;

	debug_buffer[count] = 0;

	process_dbg_cmd(debug_buffer);

	return ret;
}


static const struct file_operations debug_fops = {
	.read = debug_read,
	.write = debug_write,
	.open = debug_open,
};


void HDMI_DBG_Init(void)
{
	hdmitx_dbgfs = debugfs_create_file("hdmi", S_IFREG | S_IRUGO, NULL, (void *)0, &debug_fops);
}


void HDMI_DBG_Deinit(void)
{
	debugfs_remove(hdmitx_dbgfs);
}

#endif
