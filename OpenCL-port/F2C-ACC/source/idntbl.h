int dofold = 0;
#define HTSIZE 256
static struct idntbl_state {
	CHAIN h1l0;
	CHAIN h3l1;
	CHAIN h3l0;
	CHAIN h4l0;
	CHAIN h5l0;
	CHAIN h6l0;
	CHAIN h10l0;
	CHAIN h11l0;
	CHAIN h13l0;
	CHAIN h14l0;
	CHAIN h15l0;
	CHAIN h16l0;
	CHAIN h22l1;
	CHAIN h22l0;
	CHAIN h25l0;
	CHAIN h27l0;
	CHAIN h28l1;
	CHAIN h28l0;
	CHAIN h30l0;
	CHAIN h40l0;
	CHAIN h43l0;
	CHAIN h45l1;
	CHAIN h45l0;
	CHAIN h47l2;
	CHAIN h47l1;
	CHAIN h47l0;
	CHAIN h50l1;
	CHAIN h50l0;
	CHAIN h54l0;
	CHAIN h55l1;
	CHAIN h55l0;
	CHAIN h56l1;
	CHAIN h56l0;
	CHAIN h57l0;
	CHAIN h58l0;
	CHAIN h60l0;
	CHAIN h61l0;
	CHAIN h66l1;
	CHAIN h66l0;
	CHAIN h69l1;
	CHAIN h69l0;
	CHAIN h71l0;
	CHAIN h72l0;
	CHAIN h75l0;
	CHAIN h77l0;
	CHAIN h79l0;
	CHAIN h80l0;
	CHAIN h82l0;
	CHAIN h88l0;
	CHAIN h89l0;
	CHAIN h91l0;
	CHAIN h93l0;
	CHAIN h95l0;
	CHAIN h99l0;
	CHAIN h101l0;
	CHAIN h102l1;
	CHAIN h102l0;
	CHAIN h103l0;
	CHAIN h104l0;
	CHAIN h106l0;
	CHAIN h108l0;
	CHAIN h114l0;
	CHAIN h116l1;
	CHAIN h116l0;
	CHAIN h119l0;
	CHAIN h120l1;
	CHAIN h120l0;
	CHAIN h123l0;
	CHAIN h124l0;
	CHAIN h127l0;
	CHAIN h128l1;
	CHAIN h128l0;
	CHAIN h131l0;
	CHAIN h132l1;
	CHAIN h132l0;
	CHAIN h133l0;
	CHAIN h134l1;
	CHAIN h134l0;
	CHAIN h135l1;
	CHAIN h135l0;
	CHAIN h137l2;
	CHAIN h137l1;
	CHAIN h137l0;
	CHAIN h143l0;
	CHAIN h146l2;
	CHAIN h146l1;
	CHAIN h146l0;
	CHAIN h147l0;
	CHAIN h150l0;
	CHAIN h151l0;
	CHAIN h154l1;
	CHAIN h154l0;
	CHAIN h156l3;
	CHAIN h156l2;
	CHAIN h156l1;
	CHAIN h156l0;
	CHAIN h157l1;
	CHAIN h157l0;
	CHAIN h159l0;
	CHAIN h160l2;
	CHAIN h160l1;
	CHAIN h160l0;
	CHAIN h164l0;
	CHAIN h165l0;
	CHAIN h168l0;
	CHAIN h169l0;
	CHAIN h171l0;
	CHAIN h173l1;
	CHAIN h173l0;
	CHAIN h175l2;
	CHAIN h175l1;
	CHAIN h175l0;
	CHAIN h176l0;
	CHAIN h177l0;
	CHAIN h178l1;
	CHAIN h178l0;
	CHAIN h180l0;
	CHAIN h183l2;
	CHAIN h183l1;
	CHAIN h183l0;
	CHAIN h184l2;
	CHAIN h184l1;
	CHAIN h184l0;
	CHAIN h185l0;
	CHAIN h186l0;
	CHAIN h187l1;
	CHAIN h187l0;
	CHAIN h188l0;
	CHAIN h189l0;
	CHAIN h193l0;
	CHAIN h194l1;
	CHAIN h194l0;
	CHAIN h196l0;
	CHAIN h198l2;
	CHAIN h198l1;
	CHAIN h198l0;
	CHAIN h201l0;
	CHAIN h203l0;
	CHAIN h204l0;
	CHAIN h207l0;
	CHAIN h209l0;
	CHAIN h211l2;
	CHAIN h211l1;
	CHAIN h211l0;
	CHAIN h212l0;
	CHAIN h214l0;
	CHAIN h215l2;
	CHAIN h215l1;
	CHAIN h215l0;
	CHAIN h216l0;
	CHAIN h217l0;
	CHAIN h219l0;
	CHAIN h220l0;
	CHAIN h221l0;
	CHAIN h222l0;
	CHAIN h225l1;
	CHAIN h225l0;
	CHAIN h227l2;
	CHAIN h227l1;
	CHAIN h227l0;
	CHAIN h229l0;
	CHAIN h230l0;
	CHAIN h232l1;
	CHAIN h232l0;
	CHAIN h238l0;
	CHAIN h241l0;
	CHAIN h248l2;
	CHAIN h248l1;
	CHAIN h248l0;
	CHAIN h249l1;
	CHAIN h249l0;
	CHAIN h250l0;
	CHAIN h251l0;
	CHAIN h253l1;
	CHAIN h253l0;

	CHAIN *hash[HTSIZE];
} state = {
{NULL,7,70,39},
{NULL,10,165,113},
{&state.h3l1,7,195,143},
{NULL,10,172,120},
{NULL,5,14,8},
{NULL,5,129,84},
{NULL,5,124,79},
{NULL,5,120,75},
{NULL,7,192,140},
{NULL,10,108,68},
{NULL,8,181,129},
{NULL,5,106,66},
{NULL,6,148,103},
{&state.h22l1,5,86,52},
{NULL,5,190,138},
{NULL,5,141,96},
{NULL,10,219,161},
{&state.h28l1,6,189,137},
{NULL,5,199,146},
{NULL,4,208,154},
{NULL,5,236,175},
{NULL,5,204,150},
{&state.h45l1,4,210,156},
{NULL,10,135,90},
{&state.h47l2,5,180,128},
{&state.h47l1,4,212,158},
{NULL,5,145,100},
{&state.h50l1,4,207,153},
{NULL,8,168,116},
{NULL,4,209,155},
{&state.h55l1,3,27,11},
{NULL,12,50,24},
{&state.h56l1,10,41,19},
{NULL,10,158,107},
{NULL,10,12,6},
{NULL,4,211,157},
{NULL,4,197,145},
{NULL,8,121,76},
{&state.h66l1,6,167,115},
{NULL,8,56,28},
{&state.h69l1,6,93,57},
{NULL,15,227,169},
{NULL,6,94,58},
{NULL,3,234,173},
{NULL,8,4,2},
{NULL,8,22,10},
{NULL,10,138,93},
{NULL,8,142,97},
{NULL,3,179,127},
{NULL,8,205,151},
{NULL,8,161,109},
{NULL,8,193,141},
{NULL,8,102,64},
{NULL,8,65,34},
{NULL,8,103,65},
{NULL,8,68,37},
{&state.h102l1,8,127,82},
{NULL,7,188,136},
{NULL,6,175,123},
{NULL,6,164,112},
{NULL,8,159,108},
{NULL,4,97,61},
{NULL,11,55,27},
{&state.h116l1,4,182,130},
{NULL,4,186,134},
{NULL,11,173,121},
{&state.h120l1,6,118,73},
{NULL,6,225,167},
{NULL,4,81,47},
{NULL,6,54,26},
{NULL,6,136,91},
{&state.h128l1,6,125,80},
{NULL,4,183,131},
{NULL,4,185,133},
{&state.h132l1,4,184,132},
{NULL,6,62,32},
{NULL,6,132,87},
{&state.h134l1,4,82,48},
{NULL,13,139,94},
{&state.h135l1,6,72,41},
{NULL,6,218,160},
{&state.h137l2,6,155,106},
{&state.h137l1,6,87,53},
{NULL,5,58,30},
{NULL,13,45,22},
{&state.h146l2,11,149,104},
{&state.h146l1,6,66,35},
{NULL,6,6,4},
{NULL,11,33,15},
{NULL,9,177,125},
{NULL,11,21,9},
{&state.h154l1,4,107,67},
{NULL,6,5,3},
{&state.h156l3,4,206,152},
{&state.h156l2,4,79,45},
{&state.h156l1,4,78,44},
{NULL,11,128,83},
{&state.h157l1,9,73,42},
{NULL,6,146,101},
{NULL,11,113,70},
{&state.h160l2,6,217,159},
{&state.h160l1,4,143,98},
{NULL,4,230,172},
{NULL,9,74,43},
{NULL,5,147,102},
{NULL,4,116,71},
{NULL,9,39,18},
{NULL,9,223,165},
{&state.h173l1,5,194,142},
{NULL,7,91,55},
{&state.h175l2,4,117,72},
{&state.h175l1,4,71,40},
{NULL,4,162,110},
{NULL,9,130,85},
{NULL,9,98,62},
{&state.h178l1,4,196,144},
{NULL,4,222,164},
{NULL,9,137,92},
{&state.h183l2,9,126,81},
{&state.h183l1,9,201,147},
{NULL,11,49,23},
{&state.h184l2,7,170,118},
{&state.h184l1,7,163,111},
{NULL,4,32,14},
{NULL,4,153,105},
{NULL,7,92,56},
{&state.h187l1,4,89,54},
{NULL,4,202,148},
{NULL,9,133,88},
{NULL,9,69,38},
{NULL,4,112,69},
{&state.h194l1,4,235,174},
{NULL,9,119,74},
{NULL,9,64,33},
{&state.h198l2,7,169,117},
{&state.h198l1,4,221,163},
{NULL,9,191,139},
{NULL,9,13,7},
{NULL,9,226,168},
{NULL,2,59,31},
{NULL,7,83,49},
{NULL,9,220,162},
{&state.h211l2,9,67,36},
{&state.h211l1,2,123,78},
{NULL,7,8,5},
{NULL,2,30,12},
{NULL,9,37,16},
{&state.h215l2,7,144,99},
{&state.h215l1,2,178,126},
{NULL,9,203,149},
{NULL,5,171,119},
{NULL,7,229,171},
{NULL,12,122,77},
{NULL,5,95,59},
{NULL,5,166,114},
{NULL,9,44,21},
{&state.h225l1,7,84,50},
{NULL,5,99,63},
{&state.h227l2,5,80,46},
{&state.h227l1,2,31,13},
{NULL,7,43,20},
{NULL,12,174,122},
{NULL,12,131,86},
{&state.h232l1,9,38,17},
{NULL,7,228,170},
{NULL,5,96,60},
{NULL,7,134,89},
{&state.h248l2,7,224,166},
{&state.h248l1,5,187,135},
{NULL,7,140,95},
{&state.h249l1,5,57,29},
{NULL,5,2,1},
{NULL,7,53,25},
{NULL,7,176,124},
{&state.h253l1,5,85,51},

{
	NULL,
	&state.h1l0,
	NULL,
	&state.h3l0,
	&state.h4l0,
	&state.h5l0,
	&state.h6l0,
	NULL,
	NULL,
	NULL,
	&state.h10l0,
	&state.h11l0,
	NULL,
	&state.h13l0,
	&state.h14l0,
	&state.h15l0,
	&state.h16l0,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&state.h22l0,
	NULL,
	NULL,
	&state.h25l0,
	NULL,
	&state.h27l0,
	&state.h28l0,
	NULL,
	&state.h30l0,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&state.h40l0,
	NULL,
	NULL,
	&state.h43l0,
	NULL,
	&state.h45l0,
	NULL,
	&state.h47l0,
	NULL,
	NULL,
	&state.h50l0,
	NULL,
	NULL,
	NULL,
	&state.h54l0,
	&state.h55l0,
	&state.h56l0,
	&state.h57l0,
	&state.h58l0,
	NULL,
	&state.h60l0,
	&state.h61l0,
	NULL,
	NULL,
	NULL,
	NULL,
	&state.h66l0,
	NULL,
	NULL,
	&state.h69l0,
	NULL,
	&state.h71l0,
	&state.h72l0,
	NULL,
	NULL,
	&state.h75l0,
	NULL,
	&state.h77l0,
	NULL,
	&state.h79l0,
	&state.h80l0,
	NULL,
	&state.h82l0,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&state.h88l0,
	&state.h89l0,
	NULL,
	&state.h91l0,
	NULL,
	&state.h93l0,
	NULL,
	&state.h95l0,
	NULL,
	NULL,
	NULL,
	&state.h99l0,
	NULL,
	&state.h101l0,
	&state.h102l0,
	&state.h103l0,
	&state.h104l0,
	NULL,
	&state.h106l0,
	NULL,
	&state.h108l0,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&state.h114l0,
	NULL,
	&state.h116l0,
	NULL,
	NULL,
	&state.h119l0,
	&state.h120l0,
	NULL,
	NULL,
	&state.h123l0,
	&state.h124l0,
	NULL,
	NULL,
	&state.h127l0,
	&state.h128l0,
	NULL,
	NULL,
	&state.h131l0,
	&state.h132l0,
	&state.h133l0,
	&state.h134l0,
	&state.h135l0,
	NULL,
	&state.h137l0,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&state.h143l0,
	NULL,
	NULL,
	&state.h146l0,
	&state.h147l0,
	NULL,
	NULL,
	&state.h150l0,
	&state.h151l0,
	NULL,
	NULL,
	&state.h154l0,
	NULL,
	&state.h156l0,
	&state.h157l0,
	NULL,
	&state.h159l0,
	&state.h160l0,
	NULL,
	NULL,
	NULL,
	&state.h164l0,
	&state.h165l0,
	NULL,
	NULL,
	&state.h168l0,
	&state.h169l0,
	NULL,
	&state.h171l0,
	NULL,
	&state.h173l0,
	NULL,
	&state.h175l0,
	&state.h176l0,
	&state.h177l0,
	&state.h178l0,
	NULL,
	&state.h180l0,
	NULL,
	NULL,
	&state.h183l0,
	&state.h184l0,
	&state.h185l0,
	&state.h186l0,
	&state.h187l0,
	&state.h188l0,
	&state.h189l0,
	NULL,
	NULL,
	NULL,
	&state.h193l0,
	&state.h194l0,
	NULL,
	&state.h196l0,
	NULL,
	&state.h198l0,
	NULL,
	NULL,
	&state.h201l0,
	NULL,
	&state.h203l0,
	&state.h204l0,
	NULL,
	NULL,
	&state.h207l0,
	NULL,
	&state.h209l0,
	NULL,
	&state.h211l0,
	&state.h212l0,
	NULL,
	&state.h214l0,
	&state.h215l0,
	&state.h216l0,
	&state.h217l0,
	NULL,
	&state.h219l0,
	&state.h220l0,
	&state.h221l0,
	&state.h222l0,
	NULL,
	NULL,
	&state.h225l0,
	NULL,
	&state.h227l0,
	NULL,
	&state.h229l0,
	&state.h230l0,
	NULL,
	&state.h232l0,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&state.h238l0,
	NULL,
	NULL,
	&state.h241l0,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&state.h248l0,
	&state.h249l0,
	&state.h250l0,
	&state.h251l0,
	NULL,
	&state.h253l0,
	NULL,
	NULL}};

