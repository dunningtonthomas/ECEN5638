/*
 * SRV02_systemID_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "SRV02_systemID".
 *
 * Model version              : 9.1
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Jan 30 14:48:05 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SRV02_systemID.h"

/* Block parameters (default storage) */
P_SRV02_systemID_T SRV02_systemID_P = {
  /* Variable: T
   * Referenced by: '<Root>/Sine Wave'
   */
  15.0,

  /* Mask Parameter: HILWrite_analog_channels
   * Referenced by: '<S1>/HIL Write'
   */
  0U,

  /* Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<S1>/HIL Read Encoder'
   */
  0U,

  /* Mask Parameter: HILReadAnalog_channels
   * Referenced by: '<S1>/HIL Read Analog'
   */
  0U,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<S1>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<S1>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<S1>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<S1>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<S1>/HIL Initialize'
   */
  50.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<S1>/HIL Initialize'
   */
  0.0,

  /* Expression: -2*pi/2^12
   * Referenced by: '<S1>/Servo:  Counts to Rad'
   */
  -0.0015339807878856412,

  /* Expression: 1/6
   * Referenced by: '<Root>/Sine Wave'
   */
  0.16666666666666666,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: rand(1,N)*2*pi
   * Referenced by: '<Root>/Sine Wave'
   */
  { 2.8689484149382372, 5.6842894547833183, 1.8340634097922983,
    4.9146373819141518, 0.35127357310514357, 1.3385936573048047,
    4.8791701304315653, 4.3781873063730732, 5.70439534310612, 3.8257230329615655,
    3.4215512042364971, 4.7319783403344937, 5.5119815326364749,
    5.6157452218264128, 5.3773475944589331, 4.2929504135030667,
    2.5611171582794028, 0.300683662677895, 1.4980856628997559,
    0.087708147677018913, 2.3982914147316605, 5.6996216977659238,
    1.9075476096707848, 5.4495945100887075, 0.92471322270658785,
    1.9472382976411982, 2.627904724367665, 1.320572881968161, 4.8220611488918639,
    1.5239597318378648, 5.5677897418310085, 1.8695187009293761,
    1.1980649160089982, 4.54977692356967, 6.01181684826446, 5.6640843948561157,
    4.4019019123487837, 5.1111956732409425, 5.4439069039340993,
    5.5808078443828135, 1.4479682291469111, 3.93626188094945, 1.5327344099701714,
    2.7814412465856697, 4.9183868718521051, 4.4976883692906435,
    1.5370770121922268, 4.6359370184328856, 5.7039501883205084,
    5.2919027288034375, 6.1039022861359484, 0.89761265782499156,
    5.3841368719830545, 4.7881125782920257, 4.7768642146503666,
    2.886609173744604, 2.4132710714443757, 0.67499431589030312,
    2.8618137796912513, 0.92517716116098792, 1.8446901051065394,
    2.3902335969050021, 5.8090968614861316, 1.2155945659218066,
    4.1158039212035842, 2.4770119315542458, 1.2157086090650839,
    0.19939910097963467, 5.0379979586665771, 1.9686810804214296,
    4.6931772560584308, 3.7110645995018814, 1.8625162072999188,
    5.1239579900719541, 5.60782148537202, 3.7044578115793918, 5.1219803196436757,
    3.4879706458675153, 5.1181194222462478, 0.240984755420869, 5.33119117995033,
    0.71933586484286649, 0.94985590669205611, 4.57437562145616,
    1.2690402428067413, 4.6370438863482555, 5.4485974762491214,
    1.3134306143513141, 4.5789327264699011, 3.8534773948527965,
    3.223099266517401, 6.0276812673061952, 1.1588929930716254,
    1.2612721938602407, 4.1413774448755811, 4.6439343621484914,
    2.3522225612738281, 6.1328896208532715, 0.22123887090832087,
    2.0624335131464107, 4.0900981604606494, 0.24724550757190372,
    0.85213824886690537, 1.5000436675348008, 5.399514746668352,
    5.7458364706338285, 0.047800023514875431, 1.5468043475113011,
    3.8310446726520855, 6.1858812749215586, 6.1531936804441774,
    3.8905146482926578, 5.9584575261607009, 2.3484080951225983,
    1.4298354227978884, 3.5700008955625222, 3.5190944185576978,
    1.7662192278580178, 5.4801886615547257, 5.313291488204035,
    4.0713703169124811, 4.5469434774907338, 1.6759784172647263,
    0.76649223546584011, 0.94783574955411032, 4.1965767197188235,
    2.11460970735563, 3.88103087855394, 4.8715145224521708, 4.6051744662446454,
    4.6262060350806768, 0.37636686317706192, 1.4266010646203193,
    2.9297203107873813, 5.6483192003213967, 3.419564774380123,
    0.35900213921507812, 4.9919446177663023, 4.868520546415871,
    3.1982745798038104, 0.1618033287702641, 6.1294202276463343, 1.52284569015423,
    5.6612239275163265, 2.8172783971637454, 0.39454588138425994,
    0.62366349184225045, 2.3153422008720081, 3.2266080727261346,
    2.3880588368481726, 0.010660077696510378, 4.5086682420132922,
    2.1681762255213308, 4.1242000222938078, 1.0639631519723085,
    3.9028058211937808, 2.6679113247078554, 4.25424089309651, 1.1234975321704379,
    5.5760482205071691, 1.0048986280037977, 0.61478171327315845,
    4.7842618276199342, 5.6176461431520135, 1.5565162393798755,
    3.7525272443174948, 0.48140067004448578, 1.674767576151927,
    5.3176361361162954, 4.2980531648528189, 3.062546363550259,
    2.2417364652893634, 1.3404204724588351, 1.4378337020594261,
    4.805267329670281, 2.4890433346071519, 5.1689204980480721,
    3.2988476718611994, 0.64552782064232317, 0.30399646886167503,
    5.8991608522662569, 3.8624963148716964, 6.2322749134467728,
    2.9956836846418113, 6.1742195882253146, 3.5944007784591006,
    1.4608216033966936, 0.73524129064808763, 0.819179090468657,
    4.6610183089437873, 0.86904787086036417, 1.1759112711867425,
    2.4911304552533418, 2.111121995299257, 2.8822103687363736,
    0.64663674913836922, 1.0710796920037295, 4.0300265015380514,
    4.9491550351607749, 2.3396049042444593 },

  /* Expression: 10
   * Referenced by: '<S1>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1>/Saturation'
   */
  -10.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<S1>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<S1>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<S1>/HIL Initialize'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<S1>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<S1>/HIL Initialize'
   */
  false,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<S1>/HIL Initialize'
   */
  true,

  /* Computed Parameter: HILReadEncoder_Active
   * Referenced by: '<S1>/HIL Read Encoder'
   */
  true,

  /* Computed Parameter: HILReadAnalog_Active
   * Referenced by: '<S1>/HIL Read Analog'
   */
  true,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S1>/HIL Write'
   */
  false
};

/* Constant parameters (default storage) */
const ConstP_SRV02_systemID_T SRV02_systemID_ConstP = {
  /* Expression: (1:N)*2*pi/T
   * Referenced by: '<Root>/Sine Wave'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0,
    15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0,
    28.0, 29.0, 30.0, 31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0,
    41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0,
    54.0, 55.0, 56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0, 63.0, 64.0, 65.0, 66.0,
    67.0, 68.0, 69.0, 70.0, 71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0,
    80.0, 81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0, 91.0, 92.0,
    93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0, 101.0, 102.0, 103.0, 104.0,
    105.0, 106.0, 107.0, 108.0, 109.0, 110.0, 111.0, 112.0, 113.0, 114.0, 115.0,
    116.0, 117.0, 118.0, 119.0, 120.0, 121.0, 122.0, 123.0, 124.0, 125.0, 126.0,
    127.0, 128.0, 129.0, 130.0, 131.0, 132.0, 133.0, 134.0, 135.0, 136.0, 137.0,
    138.0, 139.0, 140.0, 141.0, 142.0, 143.0, 144.0, 145.0, 146.0, 147.0, 148.0,
    149.0, 150.0, 151.0, 152.0, 153.0, 154.0, 155.0, 156.0, 157.0, 158.0, 159.0,
    160.0, 161.0, 162.0, 163.0, 164.0, 165.0, 166.0, 167.0, 168.0, 169.0, 170.0,
    171.0, 172.0, 173.0, 174.0, 175.0, 176.0, 177.0, 178.0, 179.0, 180.0, 181.0,
    182.0, 183.0, 184.0, 185.0, 186.0, 187.0, 188.0, 189.0, 190.0, 191.0, 192.0,
    193.0, 194.0, 195.0, 196.0, 197.0, 198.0, 199.0, 200.0 }
};
