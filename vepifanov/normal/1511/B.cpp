#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

int n;
int m;
ii res[10][10][10];

int main () {
	res[1][1][1] = mp (4, 5);
	res[1][2][1] = mp (9, 67);
	res[1][3][1] = mp (4, 588);
	res[1][4][1] = mp (3, 7709);
	res[1][5][1] = mp (1, 21626);
	res[1][6][1] = mp (5, 721373);
	res[1][7][1] = mp (4, 6996319);
	res[1][8][1] = mp (5, 22506697);
	res[1][9][1] = mp (2, 116415655);
	res[2][1][1] = mp (20, 6);
	res[2][2][1] = mp (93, 88);
	res[2][2][2] = mp (38, 95);
	res[2][3][1] = mp (70, 885);
	res[2][3][2] = mp (48, 560);
	res[2][4][1] = mp (41, 2898);
	res[2][4][2] = mp (70, 6010);
	res[2][5][1] = mp (87, 96067);
	res[2][5][2] = mp (29, 58899);
	res[2][6][1] = mp (52, 515559);
	res[2][6][2] = mp (37, 518888);
	res[2][7][1] = mp (36, 7602964);
	res[2][7][2] = mp (35, 8085525);
	res[2][8][1] = mp (94, 68172046);
	res[2][8][2] = mp (20, 73950780);
	res[2][9][1] = mp (32, 801537345);
	res[2][9][2] = mp (84, 959609040);
	res[3][2][1] = mp (256, 10);
	res[3][1][1] = mp (606, 2);
	res[3][2][2] = mp (299, 69);
	res[3][3][1] = mp (535, 708);
	res[3][3][2] = mp (874, 966);
	res[4][3][1] = mp (1000, 494);
	res[3][3][3] = mp (246, 369);
	res[3][4][1] = mp (110, 2788);
	res[3][4][2] = mp (928, 1131);
	res[4][4][1] = mp (1000, 5448);
	res[3][4][3] = mp (456, 9120);
	res[3][5][1] = mp (756, 15851);
	res[3][5][2] = mp (100, 12120);
	res[3][5][3] = mp (102, 17544);
	res[3][6][1] = mp (811, 239422);
	res[3][6][2] = mp (294, 292376);
	res[3][6][3] = mp (966, 897253);
	res[3][7][1] = mp (336, 4760187);
	res[3][7][2] = mp (434, 2980460);
	res[3][7][3] = mp (240, 3383760);
	res[3][8][1] = mp (491, 52578606);
	res[3][8][2] = mp (646, 41321203);
	res[3][8][3] = mp (970, 58623405);
	res[3][9][1] = mp (596, 440756054);
	res[3][9][2] = mp (980, 315064204);
	res[4][9][1] = mp (1000, 346107267);
	res[3][9][3] = mp (188, 584012412);
	res[4][1][1] = mp (3654, 7);
	res[4][2][1] = mp (4449, 71);
	res[4][2][2] = mp (8342, 97);
	res[4][3][2] = mp (4580, 670);
	res[4][3][3] = mp (9064, 206);
	res[4][4][2] = mp (4260, 3370);
	res[4][4][3] = mp (2226, 7950);
	res[5][4][1] = mp (10000, 6772);
	res[5][4][2] = mp (10000, 9808);
	res[4][5][2] = mp (5920, 10000);
	res[4][4][4] = mp (7665, 4380);
	res[4][5][1] = mp (5805, 39197);
	res[4][5][3] = mp (9052, 40296);
	res[4][5][4] = mp (8139, 86816);
	res[4][6][1] = mp (9985, 797485);
	res[4][6][2] = mp (9814, 494172);
	res[4][6][3] = mp (3705, 872157);
	res[4][6][4] = mp (9051, 779679);
	res[4][7][1] = mp (4115, 3038104);
	res[4][7][2] = mp (4169, 4972396);
	res[4][7][3] = mp (5508, 2839986);
	res[4][7][4] = mp (2655, 6802110);
	res[4][8][1] = mp (9211, 15049500);
	res[4][8][2] = mp (5214, 29553502);
	res[4][8][3] = mp (1990, 94389879);
	res[4][8][4] = mp (9100, 77443600);
	res[4][9][2] = mp (7786, 433424894);
	res[4][9][3] = mp (1960, 915303060);
	res[4][9][4] = mp (8640, 146482560);
	res[5][1][1] = mp (15272, 8);
	res[5][2][1] = mp (97022, 73);
	res[5][2][2] = mp (70340, 80);
	res[5][3][1] = mp (28205, 520);
	res[5][3][3] = mp (10706, 848);
	res[5][3][2] = mp (74160, 940);
	res[5][4][3] = mp (73233, 3708);
	res[5][5][1] = mp (52623, 10000);
	res[5][4][4] = mp (73524, 6127);
	res[5][5][2] = mp (76973, 56914);
	res[5][5][3] = mp (83212, 75301);
	res[5][5][4] = mp (69660, 91719);
	res[5][5][5] = mp (60680, 30340);
	res[5][6][1] = mp (10725, 120918);
	res[5][6][2] = mp (25044, 966396);
	res[5][6][3] = mp (65296, 168336);
	res[5][6][4] = mp (97636, 741146);
	res[5][6][5] = mp (66015, 831789);
	res[5][7][1] = mp (76237, 8952680);
	res[5][7][2] = mp (98358, 8620950);
	res[5][7][3] = mp (39444, 7730682);
	res[5][7][4] = mp (59472, 7514712);
	res[5][7][5] = mp (75005, 6278990);
	res[5][8][1] = mp (11398, 55641335);
	res[5][8][2] = mp (42598, 81124547);
	res[5][8][3] = mp (78864, 89002317);
	res[5][8][5] = mp (59052, 51685263);
	res[5][8][4] = mp (63085, 52005910);
	res[5][9][1] = mp (37606, 793863688);
	res[5][9][2] = mp (68320, 968192995);
	res[5][9][3] = mp (20930, 853039295);
	res[5][9][4] = mp (68551, 169242626);
	res[5][9][5] = mp (13269, 747522384);
	res[6][1][1] = mp (332711, 1);
	res[6][2][1] = mp (148641, 42);
	res[6][2][2] = mp (846929, 69);
	res[6][3][1] = mp (350620, 672);
	res[6][3][2] = mp (217382, 132);
	res[6][3][3] = mp (867568, 728);
	res[6][4][1] = mp (159572, 6152);
	res[6][4][3] = mp (792379, 1884);
	res[6][4][2] = mp (242460, 2040);
	res[6][4][4] = mp (204858, 9584);
	res[6][5][1] = mp (262684, 29350);
	res[6][5][2] = mp (837903, 63415);
	res[6][5][3] = mp (712907, 70577);
	res[6][5][4] = mp (979440, 68992);
	res[6][6][1] = mp (513237, 100000);
	res[6][5][5] = mp (501320, 12533);
	res[6][6][2] = mp (372099, 190791);
	res[6][6][3] = mp (720959, 606560);
	res[6][6][4] = mp (590040, 792680);
	res[6][6][5] = mp (764856, 779020);
	res[6][6][6] = mp (684078, 912104);
	res[6][7][1] = mp (997826, 7524074);
	res[6][7][2] = mp (614760, 4654164);
	res[6][7][3] = mp (902204, 5419167);
	res[6][7][6] = mp (775401, 8787878);
	res[6][7][5] = mp (486018, 9595740);
	res[6][7][4] = mp (962826, 1248883);
	res[6][8][1] = mp (827681, 59469068);
	res[6][8][2] = mp (158125, 21387175);
	res[6][8][4] = mp (950760, 89425020);
	res[6][8][3] = mp (431002, 60033424);
	res[6][8][5] = mp (866195, 97643800);
	res[6][8][6] = mp (487662, 25602255);
	res[6][9][1] = mp (473009, 801723056);
	res[6][9][2] = mp (768014, 473582148);
	res[6][9][3] = mp (530269, 618547339);
	res[6][9][4] = mp (674050, 290341090);
	res[6][9][5] = mp (395262, 579247050);
	res[6][9][6] = mp (129468, 927508752);
	res[7][1][1] = mp (3103467, 1);
	res[7][2][1] = mp (4737618, 88);
	res[7][3][1] = mp (7846418, 100);
	res[7][2][2] = mp (5324166, 36);
	res[7][3][2] = mp (1883783, 572);
	res[7][3][3] = mp (7303292, 688);
	res[7][4][1] = mp (6838816, 6277);
	res[7][4][2] = mp (7645176, 5577);
	res[7][4][3] = mp (7425488, 7280);
	res[7][4][4] = mp (6958650, 4600);
	res[7][5][1] = mp (1368913, 60006);
	res[7][5][2] = mp (8437000, 97702);
	res[7][5][3] = mp (4934860, 91506);
	res[7][5][4] = mp (2949474, 95634);
	res[7][6][1] = mp (8873071, 100000);
	res[7][5][5] = mp (9145716, 19626);
	res[7][6][2] = mp (8612435, 364780);
	res[7][6][3] = mp (8883735, 863943);
	res[7][6][4] = mp (2169606, 101100);
	res[8][6][2] = mp (10000000, 741560);
	res[7][6][5] = mp (5084953, 640624);
	res[7][6][6] = mp (6562500, 918750);
	res[7][7][1] = mp (5531163, 4845455);
	res[7][7][2] = mp (2639000, 3681360);
	res[7][7][3] = mp (4760557, 8388629);
	res[7][7][5] = mp (1255566, 5151040);
	res[7][7][4] = mp (3535035, 9537270);
	res[7][7][6] = mp (7715032, 2522222);
	res[7][7][7] = mp (5602701, 5602701);
	res[7][8][1] = mp (3945848, 89285853);
	res[7][8][2] = mp (9841851, 51092262);
	res[7][8][3] = mp (9710712, 15978964);
	res[7][8][4] = mp (7680255, 46365440);
	res[7][8][5] = mp (9278826, 48189697);
	res[7][8][6] = mp (9169687, 86769874);
	res[7][8][7] = mp (4610512, 11526280);
	res[7][9][1] = mp (6372798, 334439863);
	res[7][9][2] = mp (6908545, 425484840);
	res[7][9][3] = mp (7798665, 297300318);
	res[7][9][4] = mp (8060853, 687230907);
	res[7][9][5] = mp (2560680, 139948275);
	res[7][9][6] = mp (2200695, 674775005);
	res[8][9][1] = mp (10000000, 886934059);
	res[7][9][7] = mp (5620433, 562043300);
	res[8][1][1] = mp (39767910, 5);
	res[8][2][1] = mp (70290427, 40);
	res[8][2][2] = mp (32101209, 21);
	res[8][3][1] = mp (83352632, 427);
	res[8][3][2] = mp (56106540, 936);
	res[8][3][3] = mp (61331066, 453);
	res[8][4][1] = mp (17902012, 5290);
	res[8][4][2] = mp (34171186, 3234);
	res[8][4][3] = mp (21256286, 5406);
	res[8][4][4] = mp (47316517, 7239);
	res[8][5][1] = mp (12065636, 25632);
	res[8][5][2] = mp (87976230, 32330);
	res[8][5][3] = mp (38807145, 17667);
	res[8][5][4] = mp (90290101, 89650);
	res[8][5][5] = mp (91113869, 95943);
	res[8][6][1] = mp (99440066, 390747);
	res[8][6][3] = mp (70800373, 620620);
	res[8][6][4] = mp (69889296, 511806);
	res[8][6][5] = mp (79742520, 862290);
	res[8][6][6] = mp (82137781, 491843);
	res[8][7][2] = mp (42001666, 3465752);
	res[8][7][1] = mp (23575598, 5957271);
	res[8][7][3] = mp (18880746, 5254212);
	res[8][7][4] = mp (62872264, 8109099);
	res[8][7][5] = mp (97316960, 5570032);
	res[8][7][6] = mp (81405415, 6467265);
	res[8][7][7] = mp (70478936, 9610764);
	res[8][8][1] = mp (93393539, 88608135);
	res[8][8][2] = mp (28758888, 13185552);
	res[8][8][3] = mp (49515977, 69623657);
	res[8][8][4] = mp (59877221, 46230116);
	res[8][8][6] = mp (84903048, 15976380);
	res[8][8][5] = mp (42931334, 35944556);
	res[8][8][7] = mp (35540232, 32806368);
	res[8][8][8] = mp (49325610, 32883740);
	res[8][9][2] = mp (49668135, 546177489);
	res[8][9][3] = mp (91491620, 154484220);
	res[8][9][4] = mp (65189572, 567324884);
	res[8][9][5] = mp (61429989, 385914384);
	res[8][9][6] = mp (84729270, 220574555);
	res[8][9][7] = mp (74847907, 161880357);
	res[8][9][8] = mp (88232640, 852915520);
	res[9][1][1] = mp (409358464, 9);
	res[9][2][1] = mp (818239031, 59);
	res[9][2][2] = mp (403446120, 33);
	res[9][3][2] = mp (477109904, 960);
	res[9][3][1] = mp (383935408, 393);
	res[9][4][1] = mp (740208841, 1000);
	res[9][3][3] = mp (665744592, 868);
	res[9][4][2] = mp (600605121, 3638);
	res[9][4][3] = mp (104980428, 8208);
	res[9][5][1] = mp (686303621, 10000);
	res[9][4][4] = mp (278616280, 6100);
	res[9][5][2] = mp (459626359, 34891);
	res[9][5][3] = mp (322977705, 19885);
	res[9][5][4] = mp (693012777, 24357);
	res[9][5][5] = mp (916349436, 55845);
	res[9][6][1] = mp (187895784, 983756);
	res[9][6][2] = mp (786405414, 625877);
	res[9][6][3] = mp (610775121, 986062);
	res[9][6][4] = mp (985832144, 709324);
	res[9][6][5] = mp (128697996, 515676);
	res[9][6][6] = mp (282093084, 172218);
	res[9][7][1] = mp (662914150, 4641212);
	res[9][7][2] = mp (841982736, 8111866);
	res[9][7][3] = mp (424974230, 6715870);
	res[9][7][4] = mp (416836792, 4732056);
	res[9][7][5] = mp (688414615, 2937207);
	res[9][7][6] = mp (493442625, 2228850);
	res[9][7][7] = mp (593127235, 9912990);
	res[9][8][1] = mp (524964785, 19712118);
	res[9][8][2] = mp (830942563, 96502219);
	res[9][8][3] = mp (628058607, 31689027);
	res[9][8][4] = mp (467868120, 30074536);
	res[9][8][5] = mp (650284824, 70083552);
	res[9][8][6] = mp (531796745, 45547875);
	res[9][8][8] = mp (232336440, 99572760);
	res[9][8][7] = mp (270560607, 81015323);
	res[9][9][1] = mp (984558482, 291151584);
	res[9][9][3] = mp (402408069, 659912918);
	res[9][9][2] = mp (172509358, 480226054);
	res[9][9][4] = mp (149646825, 931426452);
	res[9][9][5] = mp (272934704, 435792280);
	res[9][9][6] = mp (100876830, 602901945);
	res[9][9][7] = mp (226446078, 403783368);
	res[9][9][8] = mp (278745381, 216801963);
	res[9][9][9] = mp (401631578, 602447367);
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c);
		printf ("%d %d\n", res[a][b][c].fi, res[a][b][c].se);
	}
	re 0;
}