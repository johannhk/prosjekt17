#define DOF_EXPRESSION 20

struct actionUnit
{
	int AU;
	float intensity;
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

