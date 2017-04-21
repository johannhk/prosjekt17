#include <string.h>


#define DOF_EXPRESSION 20

//directions for eye movement
enum class Direction {
	Up,
	Down,
	Left,
	Right,
	Neutral
};

//structure which can be used by 
struct actionUnit
{
	//std::string action;
	//int start_intensity;
	//int stop_intensity;
	int start_time;
	double stop_time;
};


//Emotions
actionUnit neutral[DOF_EXPRESSION] = { };
actionUnit sad[DOF_EXPRESSION] = { {1,1},{15,1},{41,1} };
actionUnit happy[DOF_EXPRESSION] = { {6,1},{12,1},{25,1}  };
actionUnit suspicious[DOF_EXPRESSION] = { {9,1},{17,1},{42,1} };
actionUnit angry[DOF_EXPRESSION] = { {3,1},{4,1},{5,1},{6,1},{7,1},{23,1} };
actionUnit surprise[DOF_EXPRESSION] = { {1,1},{2,1},{5,1},{26,0.5},{27,0.5} };
actionUnit disgust[DOF_EXPRESSION] = { {4,1},{6,1},{7,1},{9,1},{10,1},{11,1},{23,1},{44,1} };
actionUnit fear[DOF_EXPRESSION] = { {1,1},{2,1},{4,1},{5,1},{7,1},{20,1},{26,0.25},{27,0.25} };
//Expressions
actionUnit smile[DOF_EXPRESSION] = { {12,1} };
actionUnit duckface[DOF_EXPRESSION] = { {18,1},{22,1} };
actionUnit pain[DOF_EXPRESSION] = { {4,1},{7,1},{9,1},{10,1},{12,1},{25,1},{26,0.5},{43,1} };
//looking directions 
actionUnit up[DOF_EXPRESSION] = { {53,0.35} };
actionUnit down[DOF_EXPRESSION] = { {54,0.35} };
actionUnit left[DOF_EXPRESSION] = { {51,0.35} };
actionUnit right[DOF_EXPRESSION] = { {52,0.35} };

//translate expression values to strings which are accepted by the trollface
static std::map<int, std::string> int_to_action {
	{1 ,  "AU01innerbrowraiser"},
	{2 ,  "AU02outerbrowraiser"},
	{201 ,  "AU02outerbrowraiserL"},
	{202 ,  "AU02outerbrowraiserR"},
	{3 ,  "AU03procerus"},
	{4 ,  "AU04browlowerer"},
	{5 ,  "AU05upperlidraiser"},
	{6 ,  "AU06cheekraiser"},
	{7 ,  "AU07lidtightener"},
	{8 ,  "AU08liptowardeachother"},
	{9 ,  "AU09nosewrinkler"},
	{10 ,  "AU10upperlipraiser"},
	{11 ,  "AU11nasolabialfurrowdeepener"},
	{12 ,  "AU12lipcornerpuller"},
	{1201 ,  "AU12lipcornerpullerL"},
	{1202 ,  "AU12lipcornerpullerR"},
	{13 ,  "AU13cheekpuffer"},
	{14 ,  "AU14dimpler"},
	{15 ,  "AU15lipcornerdepressor"},
	{16 ,  "AU16lowerlipdepressor"},
	{17 ,  "AU17chinraiser"},
	{18 ,  "AU18lippuckerer"},
	{19 ,  "AU19tongueshow"},
	{20 ,  "AU20lipstretcher"},
	{21 ,  "AU21necktightener"},
	{22 ,  "AU22lipfunneler"},
	{23 ,  "AU23liptightener"},
	{24 ,  "AU24lippressor"},
	{25 ,  "AU25lipspart"},
	{26 ,  "AU26jawopen"},
	{27 ,  "AU27mouthstretch"},
	{28 ,  "AU28lipsuck"},
	{29 ,  "AU29jawthrust"},
	{2901 ,  "AU29jawthrustN"},
	{30 ,  "AU30jawsidewaysL"},
	{3001 ,  "AU30jawsidewaysR"},
	{31 ,  "AU31jawclencher"},
	{32 ,  "AU32bite"},
	{33 ,  "AU33blow"},
	{34 ,  "AU34puff"},
	{35 ,  "AU35cheeksuck"},
	{36 ,  "AU36tonguebuldgeL"},
	{3601 ,  "AU36tonguebuldgeR"},
	{37 ,  "AU37lipwipeL"},
	{3701 ,  "AU37lipwipeM"},
	{3702 ,  "AU37lipwipeR"},
	{38 ,  "AU38nostrildilate"},
	{39 ,  "AU39nostrilcompress"},
	{40 ,  ""},
	{41 ,  "AU41liddrop"},
	{42 ,  "AU42slit"},
	{43 ,  "AU43eyesclosed"},
	{44 ,  "AU44squint"},
	{45 ,  "AU45blink"},
	{4501 ,  "AU45blink_50"},
	{46 ,  "AU46winkR"},
	{47 ,  "AU47winkL"},
	{51 ,  "AU51turnleft"},
	{52 ,  "AU52turnright"},
	{53 ,  "AU53headup"},
	{54 ,  "AU54headdown"},
	{55 ,  "AU55tiltleft"},
	{56 ,  "AU56tiltright"},
	{57 ,  "AU57headforward"},
	{58 ,  "AU58headback"},
	{66 ,  "AU66crosseye"}
};