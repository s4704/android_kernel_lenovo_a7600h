#ifndef _CUST_BATTERY_METER_TABLE_TECHNOHILL_H
#define _CUST_BATTERY_METER_TABLE_TECHNOHILL_H

#define Q_MAX_POS_50_TECHNOHILL		3013
#define Q_MAX_POS_25_TECHNOHILL		2989
#define Q_MAX_POS_0_TECHNOHILL		2531
#define Q_MAX_NEG_10_TECHNOHILL		2098

#define Q_MAX_POS_50_H_CURRENT_TECHNOHILL	2993
#define Q_MAX_POS_25_H_CURRENT_TECHNOHILL	2934
#define Q_MAX_POS_0_H_CURRENT_TECHNOHILL	2914
#define Q_MAX_NEG_10_H_CURRENT_TECHNOHILL	1076

/* Battery profile data Technohill */

#define BATTERY_PROFILE_SIZE_TECHNOHILL sizeof(battery_profile_t2_TECHNOHILL) / sizeof(BATTERY_PROFILE_STRUC);
// T0 -10C
BATTERY_PROFILE_STRUC battery_profile_t0_TECHNOHILL[] =
{
	{0	,	4366},	// VC : 4135	0mA
	{2	,	4337},	// VC : 4100	50mA
	{3	,	4311},	// VC : 4065	100mA
	{5	,	4286},	// VC : 4037	149mA
	{7	,	4263},	// VC : 4008	199mA
	{8	,	4241},	// VC : 3983	249mA
	{10	,	4219},	// VC : 3960	299mA
	{12	,	4197},	// VC : 3936	349mA
	{13	,	4175},	// VC : 3914	398mA
	{15	,	4156},	// VC : 3890	448mA
	{17	,	4134},	// VC : 3864	498mA
	{18	,	4112},	// VC : 3834	548mA
	{20	,	4087},	// VC : 3798	598mA
	{22	,	4060},	// VC : 3748	647mA
	{23	,	4035},	// VC : 3700	697mA
	{25	,	4012},	// VC : 3651	747mA
	{26	,	3990},	// VC : 3606	797mA
	{28	,	3969},	// VC : 3561	847mA
	{30	,	3948},	// VC : 3523	896mA
	{31	,	3927},	// VC : 3483	946mA
	{33	,	3906},	// VC : 3445	996mA
	{35	,	3885},	// VC : 3414	1046mA
	{36	,	3867},	// VC : 3390	1096mA
	{38	,	3854},	// VC : 3370	1146mA
	{40	,	3841},	// VC : 3357	1196mA
	{41	,	3832},	// VC : 3346	1246mA
	{43	,	3824},	// VC : 3336	1296mA
	{45	,	3815},	// VC : 3325	1346mA
	{46	,	3808},	// VC : 3310	1396mA
	{48	,	3802},	// VC : 3305	1446mA
	{50	,	3797},	// VC : 3292	1496mA
	{51	,	3791},	// VC : 3282	1546mA
	{53	,	3785},	// VC : 3271	1596mA
	{55	,	3780},	// VC : 3254	1646mA
	{56	,	3773},	// VC : 3242	1696mA
	{58	,	3765},	// VC : 3224	1746mA
	{60	,	3756},	// VC : 3205	1796mA
	{61	,	3749},	// VC : 3200	1833mA
	{63	,	3745},	// VC : 3200	1861mA
	{64	,	3739},	// VC : 3199	1883mA
	{66	,	3735},	// VC : 3199	1901mA
	{68	,	3731},	// VC : 3199	1918mA
	{69	,	3728},	// VC : 3200	1932mA
	{71	,	3724},	// VC : 3200	1945mA
	{73	,	3720},	// VC : 3199	1957mA
	{74	,	3717},	// VC : 3199	1967mA
	{76	,	3715},	// VC : 3200	1976mA
	{78	,	3712},	// VC : 3200	1984mA
	{79	,	3710},	// VC : 3200	1993mA
	{81	,	3708},	// VC : 3199	2000mA
	{83	,	3707},	// VC : 3199	2007mA
	{84	,	3706},	// VC : 3200	2014mA
	{86	,	3704},	// VC : 3199	2020mA
	{88	,	3703},	// VC : 3200	2028mA
	{89	,	3702},	// VC : 3199	2033mA
	{91	,	3701},	// VC : 3199	2039mA
	{93	,	3701},	// VC : 3199	2045mA
	{94	,	3700},	// VC : 3199	2050mA
	{96	,	3699},	// VC : 3200	2056mA
	{98	,	3698},	// VC : 3199	2062mA
	{99	,	3698},	// VC : 3200	2067mA
	{100	,	3698},	// VC : 3199	2071mA
	{100	,	3698},	// VC : 3199	2076mA
	{100	,	3697},	// VC : 3199	2080mA
	{100	,	3697},	// VC : 3199	2084mA
	{100	,	3696},	// VC : 3199	2088mA
	{100	,	3696},	// VC : 3200	2091mA
	{100	,	3696},	// VC : 3200	2095mA
	{100	,	3400},	// VC : 3200	2098mA
};

// T1 0C
BATTERY_PROFILE_STRUC battery_profile_t1_TECHNOHILL[] =
{
	{0	,	4383},	// VC : 4265	0mA
	{2	,	4358},	// VC : 4235	50mA
	{5	,	4331},	// VC : 4203	100mA
	{7	,	4298},	// VC : 4166	150mA
	{9	,	4262},	// VC : 4117	200mA
	{12	,	4231},	// VC : 4071	250mA
	{14	,	4203},	// VC : 4032	300mA
	{17	,	4177},	// VC : 3997	350mA
	{19	,	4154},	// VC : 3965	400mA
	{21	,	4132},	// VC : 3935	450mA
	{24	,	4110},	// VC : 3905	500mA
	{26	,	4090},	// VC : 3880	550mA
	{29	,	4069},	// VC : 3851	600mA
	{31	,	4051},	// VC : 3828	650mA
	{33	,	4032},	// VC : 3805	700mA
	{36	,	4015},	// VC : 3784	750mA
	{38	,	3996},	// VC : 3765	800mA
	{40	,	3955},	// VC : 3724	914mA
	{43	,	3934},	// VC : 3707	964mA
	{45	,	3916},	// VC : 3692	1014mA
	{47	,	3900},	// VC : 3675	1064mA
	{50	,	3885},	// VC : 3661	1114mA
	{52	,	3872},	// VC : 3647	1164mA
	{55	,	3861},	// VC : 3634	1214mA
	{57	,	3851},	// VC : 3625	1264mA
	{59	,	3842},	// VC : 3612	1314mA
	{62	,	3834},	// VC : 3603	1364mA
	{64	,	3826},	// VC : 3591	1414mA
	{67	,	3818},	// VC : 3580	1464mA
	{69	,	3811},	// VC : 3569	1514mA
	{71	,	3805},	// VC : 3560	1564mA
	{74	,	3799},	// VC : 3551	1614mA
	{76	,	3792},	// VC : 3542	1664mA
	{78	,	3787},	// VC : 3534	1714mA
	{81	,	3782},	// VC : 3526	1763mA
	{83	,	3777},	// VC : 3517	1813mA
	{86	,	3771},	// VC : 3508	1863mA
	{87	,	3765},	// VC : 3498	1913mA
	{89	,	3758},	// VC : 3486	1963mA
	{90	,	3750},	// VC : 3472	2013mA
	{91	,	3739},	// VC : 3455	2062mA
	{91	,	3727},	// VC : 3434	2112mA
	{92	,	3714},	// VC : 3414	2162mA
	{93	,	3703},	// VC : 3392	2212mA
	{93	,	3696},	// VC : 3366	2262mA
	{94	,	3688},	// VC : 3333	2311mA
	{94	,	3682},	// VC : 3285	2361mA
	{95	,	3673},	// VC : 3218	2411mA
	{95	,	3666},	// VC : 3199	2439mA
	{95	,	3660},	// VC : 3200	2457mA
	{96	,	3655},	// VC : 3199	2471mA
	{96	,	3650},	// VC : 3200	2483mA
	{96	,	3643},	// VC : 3199	2493mA
	{97	,	3638},	// VC : 3199	2501mA
	{97	,	3631},	// VC : 3200	2509mA
	{97	,	3625},	// VC : 3198	2515mA
	{97	,	3620},	// VC : 3200	2521mA
	{98	,	3613},	// VC : 3199	2526mA
	{98	,	3400},	// VC : 3199	2531mA
	{98	,	3400},	// VC : 3199	2531mA
	{99	,	3400},	// VC : 3199	2531mA
	{99	,	3400},	// VC : 3199	2531mA
	{99	,	3400},	// VC : 3199	2531mA
	{99	,	3400},	// VC : 3199	2531mA
	{99	,	3400},	// VC : 3199	2531mA
	{100	,	3400},	// VC : 3199	2531mA
	{100	,	3400},	// VC : 3199	2531mA
	{100	,	3400},	// VC : 3199	2531mA
	{100	,	3400},	// VC : 3199	2531mA
};

// T2 25C
BATTERY_PROFILE_STRUC battery_profile_t2_TECHNOHILL[] =
{
	{0	,	4384},	// VC : 4310	0mA
	{2	,	4358},	// VC : 4288	50mA
	{3	,	4338},	// VC : 4266	100mA
	{5	,	4317},	// VC : 4245	150mA
	{7	,	4298},	// VC : 4225	199mA
	{8	,	4278},	// VC : 4203	249mA
	{10	,	4258},	// VC : 4181	299mA
	{12	,	4237},	// VC : 4159	349mA
	{13	,	4218},	// VC : 4138	399mA
	{15	,	4198},	// VC : 4118	449mA
	{17	,	4179},	// VC : 4095	498mA
	{18	,	4160},	// VC : 4074	548mA
	{20	,	4141},	// VC : 4054	598mA
	{22	,	4122},	// VC : 4033	648mA
	{23	,	4104},	// VC : 4013	698mA
	{25	,	4087},	// VC : 3993	747mA
	{27	,	4069},	// VC : 3974	797mA
	{28	,	4053},	// VC : 3955	847mA
	{30	,	4036},	// VC : 3937	897mA
	{32	,	4021},	// VC : 3919	947mA
	{33	,	4006},	// VC : 3902	996mA
	{35	,	3991},	// VC : 3887	1046mA
	{37	,	3976},	// VC : 3871	1096mA
	{38	,	3960},	// VC : 3856	1146mA
	{40	,	3944},	// VC : 3842	1196mA
	{42	,	3926},	// VC : 3830	1245mA
	{43	,	3909},	// VC : 3819	1295mA
	{45	,	3892},	// VC : 3807	1345mA
	{47	,	3878},	// VC : 3796	1395mA
	{48	,	3865},	// VC : 3787	1445mA
	{50	,	3855},	// VC : 3777	1495mA
	{52	,	3845},	// VC : 3767	1544mA
	{53	,	3837},	// VC : 3758	1594mA
	{55	,	3830},	// VC : 3749	1644mA
	{57	,	3823},	// VC : 3741	1694mA
	{58	,	3816},	// VC : 3733	1744mA
	{60	,	3809},	// VC : 3727	1794mA
	{62	,	3804},	// VC : 3722	1844mA
	{63	,	3798},	// VC : 3716	1893mA
	{65	,	3793},	// VC : 3711	1943mA
	{67	,	3789},	// VC : 3706	1993mA
	{68	,	3785},	// VC : 3701	2043mA
	{70	,	3780},	// VC : 3696	2093mA
	{72	,	3777},	// VC : 3692	2143mA
	{73	,	3773},	// VC : 3688	2193mA
	{75	,	3769},	// VC : 3684	2242mA
	{77	,	3763},	// VC : 3679	2292mA
	{78	,	3757},	// VC : 3673	2342mA
	{80	,	3749},	// VC : 3666	2392mA
	{82	,	3742},	// VC : 3657	2442mA
	{83	,	3730},	// VC : 3646	2491mA
	{85	,	3717},	// VC : 3631	2541mA
	{87	,	3701},	// VC : 3615	2591mA
	{88	,	3691},	// VC : 3606	2641mA
	{90	,	3686},	// VC : 3600	2691mA
	{92	,	3683},	// VC : 3591	2740mA
	{93	,	3678},	// VC : 3576	2790mA
	{95	,	3669},	// VC : 3554	2840mA
	{97	,	3632},	// VC : 3502	2890mA
	{98	,	3543},	// VC : 3386	2940mA
	{100	,	3415},	// VC : 3200	2984mA
	{100	,	3372},	// VC : 3199	2996mA
	{100	,	3346},	// VC : 3198	3002mA
	{100	,	3328},	// VC : 3198	3006mA
	{100	,	3318},	// VC : 3200	3008mA
	{100	,	3311},	// VC : 3199	3009mA
	{100	,	3306},	// VC : 3197	3010mA
	{100	,	3302},	// VC : 3199	3011mA
	{100	,	3302},	// VC : 3198	3011mA
};

// T3 50C
BATTERY_PROFILE_STRUC battery_profile_t3_TECHNOHILL[] =
{
	{0	,	4391},	// VC : 4345	0mA
	{2	,	4370},	// VC : 4319	50mA
	{3	,	4351},	// VC : 4300	100mA
	{5	,	4332},	// VC : 4281	150mA
	{7	,	4313},	// VC : 4262	199mA
	{8	,	4293},	// VC : 4242	249mA
	{10	,	4274},	// VC : 4221	299mA
	{12	,	4254},	// VC : 4201	349mA
	{13	,	4234},	// VC : 4181	399mA
	{15	,	4214},	// VC : 4161	448mA
	{17	,	4195},	// VC : 4141	498mA
	{18	,	4176},	// VC : 4121	548mA
	{20	,	4157},	// VC : 4101	598mA
	{22	,	4137},	// VC : 4082	648mA
	{23	,	4119},	// VC : 4062	697mA
	{25	,	4101},	// VC : 4044	747mA
	{26	,	4083},	// VC : 4026	797mA
	{28	,	4067},	// VC : 4007	847mA
	{30	,	4049},	// VC : 3990	897mA
	{31	,	4033},	// VC : 3973	946mA
	{33	,	4017},	// VC : 3956	996mA
	{35	,	4002},	// VC : 3941	1046mA
	{36	,	3988},	// VC : 3925	1096mA
	{38	,	3974},	// VC : 3909	1146mA
	{40	,	3960},	// VC : 3893	1195mA
	{41	,	3947},	// VC : 3878	1245mA
	{43	,	3933},	// VC : 3863	1295mA
	{45	,	3914},	// VC : 3849	1345mA
	{46	,	3893},	// VC : 3835	1395mA
	{48	,	3878},	// VC : 3823	1445mA
	{50	,	3865},	// VC : 3812	1494mA
	{51	,	3854},	// VC : 3801	1544mA
	{53	,	3845},	// VC : 3792	1594mA
	{55	,	3837},	// VC : 3783	1644mA
	{56	,	3829},	// VC : 3775	1694mA
	{58	,	3822},	// VC : 3766	1743mA
	{60	,	3814},	// VC : 3759	1793mA
	{61	,	3808},	// VC : 3750	1843mA
	{63	,	3802},	// VC : 3744	1893mA
	{64	,	3796},	// VC : 3737	1943mA
	{66	,	3791},	// VC : 3732	1992mA
	{68	,	3786},	// VC : 3726	2042mA
	{69	,	3781},	// VC : 3721	2092mA
	{71	,	3776},	// VC : 3716	2142mA
	{73	,	3767},	// VC : 3709	2192mA
	{74	,	3756},	// VC : 3702	2241mA
	{76	,	3750},	// VC : 3695	2291mA
	{78	,	3744},	// VC : 3688	2341mA
	{79	,	3736},	// VC : 3681	2391mA
	{81	,	3729},	// VC : 3674	2441mA
	{83	,	3722},	// VC : 3666	2490mA
	{84	,	3711},	// VC : 3655	2540mA
	{86	,	3697},	// VC : 3642	2590mA
	{88	,	3680},	// VC : 3626	2640mA
	{89	,	3673},	// VC : 3619	2690mA
	{91	,	3671},	// VC : 3614	2739mA
	{93	,	3668},	// VC : 3609	2789mA
	{94	,	3663},	// VC : 3601	2839mA
	{96	,	3650},	// VC : 3586	2889mA
	{98	,	3590},	// VC : 3527	2939mA
	{99	,	3488},	// VC : 3419	2988mA
	{100	,	3308},	// VC : 3227	3038mA
	{100	,	3266},	// VC : 3200	3046mA
	{100	,	3257},	// VC : 3199	3048mA
	{100	,	3252},	// VC : 3198	3049mA
	{100	,	3251},	// VC : 3199	3049mA
	{100	,	3250},	// VC : 3200	3050mA
	{100	,	3249},	// VC : 3199	3050mA
	{100	,	3249},	// VC : 3199	3050mA
};

// battery profile for actual temperature. The size should be the same as T1, T2 and T3
BATTERY_PROFILE_STRUC battery_profile_temperature_TECHNOHILL[] =
{
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
};

#define R_PROFILE_SIZE_TECHNOHILL sizeof(r_profile_t2_TECHNOHILL) / sizeof(R_PROFILE_STRUC);
// ============================================================
// <Rbat, Battery_Voltage> Table
// ============================================================
// T0 -10C
R_PROFILE_STRUC r_profile_t0_TECHNOHILL[] =
{
	{593	,	4366},		// VC : 4135	0mA
	{593	,	4337},		// VC : 4100	50mA
	{615	,	4311},		// VC : 4065	100mA
	{623	,	4286},		// VC : 4037	149mA
	{638	,	4263},		// VC : 4008	199mA
	{645	,	4241},		// VC : 3983	249mA
	{648	,	4219},		// VC : 3960	299mA
	{653	,	4197},		// VC : 3936	349mA
	{653	,	4175},		// VC : 3914	398mA
	{665	,	4156},		// VC : 3890	448mA
	{675	,	4134},		// VC : 3864	498mA
	{695	,	4112},		// VC : 3834	548mA
	{723	,	4087},		// VC : 3798	598mA
	{780	,	4060},		// VC : 3748	647mA
	{838	,	4035},		// VC : 3700	697mA
	{903	,	4012},		// VC : 3651	747mA
	{960	,	3990},		// VC : 3606	797mA
	{1020	,	3969},		// VC : 3561	847mA
	{1063	,	3948},		// VC : 3523	896mA
	{1110	,	3927},		// VC : 3483	946mA
	{1153	,	3906},		// VC : 3445	996mA
	{1178	,	3885},		// VC : 3414	1046mA
	{1193	,	3867},		// VC : 3390	1096mA
	{1210	,	3854},		// VC : 3370	1146mA
	{1210	,	3841},		// VC : 3357	1196mA
	{1215	,	3832},		// VC : 3346	1246mA
	{1220	,	3824},		// VC : 3336	1296mA
	{1225	,	3815},		// VC : 3325	1346mA
	{1245	,	3808},		// VC : 3310	1396mA
	{1243	,	3802},		// VC : 3305	1446mA
	{1263	,	3797},		// VC : 3292	1496mA
	{1273	,	3791},		// VC : 3282	1546mA
	{1285	,	3785},		// VC : 3271	1596mA
	{1315	,	3780},		// VC : 3254	1646mA
	{1328	,	3773},		// VC : 3242	1696mA
	{1353	,	3765},		// VC : 3224	1746mA
	{1378	,	3756},		// VC : 3205	1796mA
	{1373	,	3749},		// VC : 3200	1833mA
	{1363	,	3745},		// VC : 3200	1861mA
	{1350	,	3739},		// VC : 3199	1883mA
	{1340	,	3735},		// VC : 3199	1901mA
	{1330	,	3731},		// VC : 3199	1918mA
	{1320	,	3728},		// VC : 3200	1932mA
	{1310	,	3724},		// VC : 3200	1945mA
	{1303	,	3720},		// VC : 3199	1957mA
	{1295	,	3717},		// VC : 3199	1967mA
	{1288	,	3715},		// VC : 3200	1976mA
	{1280	,	3712},		// VC : 3200	1984mA
	{1275	,	3710},		// VC : 3200	1993mA
	{1273	,	3708},		// VC : 3199	2000mA
	{1270	,	3707},		// VC : 3199	2007mA
	{1265	,	3706},		// VC : 3200	2014mA
	{1263	,	3704},		// VC : 3199	2020mA
	{1258	,	3703},		// VC : 3200	2028mA
	{1258	,	3702},		// VC : 3199	2033mA
	{1255	,	3701},		// VC : 3199	2039mA
	{1255	,	3701},		// VC : 3199	2045mA
	{1253	,	3700},		// VC : 3199	2050mA
	{1248	,	3699},		// VC : 3200	2056mA
	{1248	,	3698},		// VC : 3199	2062mA
	{1245	,	3698},		// VC : 3200	2067mA
	{1248	,	3698},		// VC : 3199	2071mA
	{1248	,	3698},		// VC : 3199	2076mA
	{1245	,	3697},		// VC : 3199	2080mA
	{1245	,	3697},		// VC : 3199	2084mA
	{1243	,	3696},		// VC : 3199	2088mA
	{1240	,	3696},		// VC : 3200	2091mA
	{1240	,	3696},		// VC : 3200	2095mA
	{500	,	3400},		// VC : 3200	2098mA
};

// T1 0C
R_PROFILE_STRUC r_profile_t1_TECHNOHILL[] =
{
	{308	,	4383},		// VC : 4265	0mA
	{308	,	4358},		// VC : 4235	50mA
	{320	,	4331},		// VC : 4203	100mA
	{330	,	4298},		// VC : 4166	150mA
	{363	,	4262},		// VC : 4117	200mA
	{400	,	4231},		// VC : 4071	250mA
	{428	,	4203},		// VC : 4032	300mA
	{450	,	4177},		// VC : 3997	350mA
	{473	,	4154},		// VC : 3965	400mA
	{493	,	4132},		// VC : 3935	450mA
	{513	,	4110},		// VC : 3905	500mA
	{525	,	4090},		// VC : 3880	550mA
	{545	,	4069},		// VC : 3851	600mA
	{558	,	4051},		// VC : 3828	650mA
	{568	,	4032},		// VC : 3805	700mA
	{578	,	4015},		// VC : 3784	750mA
	{578	,	3996},		// VC : 3765	800mA
	{578	,	3955},		// VC : 3724	914mA
	{568	,	3934},		// VC : 3707	964mA
	{560	,	3916},		// VC : 3692	1014mA
	{563	,	3900},		// VC : 3675	1064mA
	{560	,	3885},		// VC : 3661	1114mA
	{563	,	3872},		// VC : 3647	1164mA
	{568	,	3861},		// VC : 3634	1214mA
	{565	,	3851},		// VC : 3625	1264mA
	{575	,	3842},		// VC : 3612	1314mA
	{578	,	3834},		// VC : 3603	1364mA
	{588	,	3826},		// VC : 3591	1414mA
	{595	,	3818},		// VC : 3580	1464mA
	{605	,	3811},		// VC : 3569	1514mA
	{613	,	3805},		// VC : 3560	1564mA
	{620	,	3799},		// VC : 3551	1614mA
	{625	,	3792},		// VC : 3542	1664mA
	{633	,	3787},		// VC : 3534	1714mA
	{640	,	3782},		// VC : 3526	1763mA
	{650	,	3777},		// VC : 3517	1813mA
	{658	,	3771},		// VC : 3508	1863mA
	{668	,	3765},		// VC : 3498	1913mA
	{680	,	3758},		// VC : 3486	1963mA
	{695	,	3750},		// VC : 3472	2013mA
	{710	,	3739},		// VC : 3455	2062mA
	{733	,	3727},		// VC : 3434	2112mA
	{750	,	3714},		// VC : 3414	2162mA
	{778	,	3703},		// VC : 3392	2212mA
	{825	,	3696},		// VC : 3366	2262mA
	{888	,	3688},		// VC : 3333	2311mA
	{993	,	3682},		// VC : 3285	2361mA
	{1138	,	3673},		// VC : 3218	2411mA
	{1168	,	3666},		// VC : 3199	2439mA
	{1150	,	3660},		// VC : 3200	2457mA
	{1140	,	3655},		// VC : 3199	2471mA
	{1125	,	3650},		// VC : 3200	2483mA
	{1110	,	3643},		// VC : 3199	2493mA
	{1098	,	3638},		// VC : 3199	2501mA
	{1078	,	3631},		// VC : 3200	2509mA
	{1068	,	3625},		// VC : 3198	2515mA
	{1050	,	3620},		// VC : 3200	2521mA
	{1035	,	3613},		// VC : 3199	2526mA
	{503	,	3400},		// VC : 3199	2531mA
	{503	,	3400},		// VC : 3199	2531mA
	{503	,	3400},		// VC : 3199	2531mA
	{503	,	3400},		// VC : 3199	2531mA
	{503	,	3400},		// VC : 3199	2531mA
	{503	,	3400},		// VC : 3199	2531mA
	{503	,	3400},		// VC : 3199	2531mA
	{503	,	3400},		// VC : 3199	2531mA
	{503	,	3400},		// VC : 3199	2531mA
	{503	,	3400},		// VC : 3199	2531mA
	{503	,	3400},		// VC : 3199	2531mA
};

// T2 25C
R_PROFILE_STRUC r_profile_t2_TECHNOHILL[] =
{
	{175	,	4384},		// VC : 4310	0mA
	{175	,	4358},		// VC : 4288	50mA
	{180	,	4338},		// VC : 4266	100mA
	{180	,	4317},		// VC : 4245	150mA
	{183	,	4298},		// VC : 4225	199mA
	{188	,	4278},		// VC : 4203	249mA
	{193	,	4258},		// VC : 4181	299mA
	{195	,	4237},		// VC : 4159	349mA
	{200	,	4218},		// VC : 4138	399mA
	{200	,	4198},		// VC : 4118	449mA
	{210	,	4179},		// VC : 4095	498mA
	{215	,	4160},		// VC : 4074	548mA
	{218	,	4141},		// VC : 4054	598mA
	{223	,	4122},		// VC : 4033	648mA
	{228	,	4104},		// VC : 4013	698mA
	{235	,	4087},		// VC : 3993	747mA
	{238	,	4069},		// VC : 3974	797mA
	{245	,	4053},		// VC : 3955	847mA
	{248	,	4036},		// VC : 3937	897mA
	{255	,	4021},		// VC : 3919	947mA
	{260	,	4006},		// VC : 3902	996mA
	{260	,	3991},		// VC : 3887	1046mA
	{263	,	3976},		// VC : 3871	1096mA
	{260	,	3960},		// VC : 3856	1146mA
	{255	,	3944},		// VC : 3842	1196mA
	{240	,	3926},		// VC : 3830	1245mA
	{225	,	3909},		// VC : 3819	1295mA
	{213	,	3892},		// VC : 3807	1345mA
	{205	,	3878},		// VC : 3796	1395mA
	{195	,	3865},		// VC : 3787	1445mA
	{195	,	3855},		// VC : 3777	1495mA
	{195	,	3845},		// VC : 3767	1544mA
	{198	,	3837},		// VC : 3758	1594mA
	{203	,	3830},		// VC : 3749	1644mA
	{205	,	3823},		// VC : 3741	1694mA
	{208	,	3816},		// VC : 3733	1744mA
	{205	,	3809},		// VC : 3727	1794mA
	{205	,	3804},		// VC : 3722	1844mA
	{205	,	3798},		// VC : 3716	1893mA
	{205	,	3793},		// VC : 3711	1943mA
	{208	,	3789},		// VC : 3706	1993mA
	{210	,	3785},		// VC : 3701	2043mA
	{210	,	3780},		// VC : 3696	2093mA
	{213	,	3777},		// VC : 3692	2143mA
	{213	,	3773},		// VC : 3688	2193mA
	{213	,	3769},		// VC : 3684	2242mA
	{210	,	3763},		// VC : 3679	2292mA
	{210	,	3757},		// VC : 3673	2342mA
	{208	,	3749},		// VC : 3666	2392mA
	{213	,	3742},		// VC : 3657	2442mA
	{210	,	3730},		// VC : 3646	2491mA
	{215	,	3717},		// VC : 3631	2541mA
	{215	,	3701},		// VC : 3615	2591mA
	{213	,	3691},		// VC : 3606	2641mA
	{215	,	3686},		// VC : 3600	2691mA
	{230	,	3683},		// VC : 3591	2740mA
	{255	,	3678},		// VC : 3576	2790mA
	{288	,	3669},		// VC : 3554	2840mA
	{325	,	3632},		// VC : 3502	2890mA
	{393	,	3543},		// VC : 3386	2940mA
	{538	,	3415},		// VC : 3200	2984mA
	{433	,	3372},		// VC : 3199	2996mA
	{370	,	3346},		// VC : 3198	3002mA
	{325	,	3328},		// VC : 3198	3006mA
	{295	,	3318},		// VC : 3200	3008mA
	{280	,	3311},		// VC : 3199	3009mA
	{273	,	3306},		// VC : 3197	3010mA
	{258	,	3302},		// VC : 3199	3011mA
	{260	,	3302},		// VC : 3198	3011mA
};

// T3 50C
R_PROFILE_STRUC r_profile_t3_TECHNOHILL[] =
{
	{128	,	4391},		// VC : 4345	0mA
	{128	,	4370},		// VC : 4319	50mA
	{128	,	4351},		// VC : 4300	100mA
	{128	,	4332},		// VC : 4281	150mA
	{128	,	4313},		// VC : 4262	199mA
	{128	,	4293},		// VC : 4242	249mA
	{133	,	4274},		// VC : 4221	299mA
	{133	,	4254},		// VC : 4201	349mA
	{133	,	4234},		// VC : 4181	399mA
	{133	,	4214},		// VC : 4161	448mA
	{135	,	4195},		// VC : 4141	498mA
	{138	,	4176},		// VC : 4121	548mA
	{140	,	4157},		// VC : 4101	598mA
	{138	,	4137},		// VC : 4082	648mA
	{143	,	4119},		// VC : 4062	697mA
	{143	,	4101},		// VC : 4044	747mA
	{143	,	4083},		// VC : 4026	797mA
	{150	,	4067},		// VC : 4007	847mA
	{148	,	4049},		// VC : 3990	897mA
	{150	,	4033},		// VC : 3973	946mA
	{153	,	4017},		// VC : 3956	996mA
	{153	,	4002},		// VC : 3941	1046mA
	{158	,	3988},		// VC : 3925	1096mA
	{163	,	3974},		// VC : 3909	1146mA
	{168	,	3960},		// VC : 3893	1195mA
	{173	,	3947},		// VC : 3878	1245mA
	{175	,	3933},		// VC : 3863	1295mA
	{163	,	3914},		// VC : 3849	1345mA
	{145	,	3893},		// VC : 3835	1395mA
	{138	,	3878},		// VC : 3823	1445mA
	{133	,	3865},		// VC : 3812	1494mA
	{133	,	3854},		// VC : 3801	1544mA
	{133	,	3845},		// VC : 3792	1594mA
	{135	,	3837},		// VC : 3783	1644mA
	{135	,	3829},		// VC : 3775	1694mA
	{140	,	3822},		// VC : 3766	1743mA
	{138	,	3814},		// VC : 3759	1793mA
	{145	,	3808},		// VC : 3750	1843mA
	{145	,	3802},		// VC : 3744	1893mA
	{148	,	3796},		// VC : 3737	1943mA
	{148	,	3791},		// VC : 3732	1992mA
	{150	,	3786},		// VC : 3726	2042mA
	{150	,	3781},		// VC : 3721	2092mA
	{150	,	3776},		// VC : 3716	2142mA
	{145	,	3767},		// VC : 3709	2192mA
	{135	,	3756},		// VC : 3702	2241mA
	{138	,	3750},		// VC : 3695	2291mA
	{140	,	3744},		// VC : 3688	2341mA
	{138	,	3736},		// VC : 3681	2391mA
	{138	,	3729},		// VC : 3674	2441mA
	{140	,	3722},		// VC : 3666	2490mA
	{140	,	3711},		// VC : 3655	2540mA
	{138	,	3697},		// VC : 3642	2590mA
	{135	,	3680},		// VC : 3626	2640mA
	{135	,	3673},		// VC : 3619	2690mA
	{143	,	3671},		// VC : 3614	2739mA
	{148	,	3668},		// VC : 3609	2789mA
	{155	,	3663},		// VC : 3601	2839mA
	{160	,	3650},		// VC : 3586	2889mA
	{158	,	3590},		// VC : 3527	2939mA
	{173	,	3488},		// VC : 3419	2988mA
	{203	,	3308},		// VC : 3227	3038mA
	{165	,	3266},		// VC : 3200	3046mA
	{145	,	3257},		// VC : 3199	3048mA
	{135	,	3252},		// VC : 3198	3049mA
	{130	,	3251},		// VC : 3199	3049mA
	{125	,	3250},		// VC : 3200	3050mA
	{125	,	3249},		// VC : 3199	3050mA
	{125	,	3249},		// VC : 3199	3050mA
};

// r-table profile for actual temperature. The size should be the same as T1, T2 and T3
R_PROFILE_STRUC r_profile_temperature_TECHNOHILL[] =
{
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
};
#endif /* _CUST_BATTERY_METER_TABLE_TECHNOHILL_H */
