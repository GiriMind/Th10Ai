#pragma once

namespace th
{
	// 移动方向
	enum Direction
	{
		DIR_NONE = -1,
		DIR_HOLD,			// 不动
		DIR_UP,				// 上
		DIR_DOWN,			// 下
		DIR_LEFT,			// 左
		DIR_RIGHT,			// 右
		DIR_UPLEFT,			// 左上
		DIR_UPRIGHT,		// 右上
		DIR_DOWNLEFT,		// 左下
		DIR_DOWNRIGHT,		// 右下
		DIR_MAXCOUNT
	};

	const Direction DODGE_PRIORITY[DIR_MAXCOUNT][5] =
	{
		// DIR_HOLD
		{ DIR_NONE,    DIR_NONE,      DIR_NONE,     DIR_NONE,      DIR_NONE      },
		// DIR_UP
		{ DIR_LEFT,    DIR_RIGHT,     DIR_UPLEFT,   DIR_UPRIGHT,   DIR_UP        },
		// DIR_DOWN
		{ DIR_LEFT,    DIR_RIGHT,     DIR_DOWNLEFT, DIR_DOWNRIGHT, DIR_DOWN      },
		// DIR_LEFT
		{ DIR_UP,      DIR_DOWN,      DIR_UPLEFT,   DIR_DOWNLEFT,  DIR_LEFT      },
		// DIR_RIGHT
		{ DIR_UP,      DIR_DOWN,      DIR_UPRIGHT,  DIR_DOWNRIGHT, DIR_RIGHT     },
		// DIR_UPLEFT
		{ DIR_UPRIGHT, DIR_DOWNLEFT,  DIR_UP,       DIR_LEFT,      DIR_UPLEFT    },
		// DIR_UPRIGHT
		{ DIR_UPLEFT,  DIR_DOWNRIGHT, DIR_UP,       DIR_RIGHT,     DIR_UPRIGHT   },
		// DIR_DOWNLEFT
		{ DIR_UPLEFT,  DIR_DOWNRIGHT, DIR_DOWN,     DIR_LEFT,      DIR_DOWNLEFT  },
		// DIR_DOWNRIGHT
		{ DIR_UPRIGHT, DIR_DOWNLEFT,  DIR_DOWN,     DIR_RIGHT,     DIR_DOWNRIGHT }
	};

	const Direction MOVE_PRIORITY_DIR[DIR_MAXCOUNT][9] =
	{
		// DIR_HOLD
		{ DIR_HOLD,      DIR_UP,       DIR_DOWN,      DIR_LEFT,    DIR_RIGHT,     DIR_UPLEFT,  DIR_UPRIGHT,  DIR_DOWNLEFT,  DIR_DOWNRIGHT },
		// DIR_UP
		{ DIR_UP,        DIR_UPLEFT,   DIR_UPRIGHT,   DIR_LEFT,    DIR_RIGHT,     DIR_HOLD,    DIR_NONE,     DIR_NONE,      DIR_NONE      },
		// DIR_DOWN
		{ DIR_DOWN,      DIR_DOWNLEFT, DIR_DOWNRIGHT, DIR_LEFT,    DIR_RIGHT,     DIR_HOLD,    DIR_NONE,     DIR_NONE,      DIR_NONE      },
		// DIR_LEFT
		{ DIR_LEFT,      DIR_UPLEFT,   DIR_DOWNLEFT,  DIR_UP,      DIR_DOWN,      DIR_HOLD,    DIR_NONE,     DIR_NONE,      DIR_NONE      },
		// DIR_RIGHT
		{ DIR_RIGHT,     DIR_UPRIGHT,  DIR_DOWNRIGHT, DIR_UP,      DIR_DOWN,      DIR_HOLD,    DIR_NONE,     DIR_NONE,      DIR_NONE      },
		// DIR_UPLEFT
		{ DIR_UPLEFT,    DIR_UP,       DIR_LEFT,      DIR_UPRIGHT, DIR_DOWNLEFT,  DIR_HOLD,    DIR_NONE,     DIR_NONE,      DIR_NONE      },
		// DIR_UPRIGHT
		{ DIR_UPRIGHT,   DIR_UP,       DIR_RIGHT,     DIR_UPLEFT,  DIR_DOWNRIGHT, DIR_HOLD,    DIR_NONE,     DIR_NONE,      DIR_NONE      },
		// DIR_DOWNLEFT
		{ DIR_DOWNLEFT,  DIR_DOWN,     DIR_LEFT,      DIR_UPLEFT,  DIR_DOWNRIGHT, DIR_HOLD,    DIR_NONE,     DIR_NONE,      DIR_NONE      },
		// DIR_DOWNRIGHT
		{ DIR_DOWNRIGHT, DIR_DOWN,     DIR_RIGHT,     DIR_UPRIGHT, DIR_DOWNLEFT,  DIR_HOLD,    DIR_NONE,     DIR_NONE,      DIR_NONE      }
	};

	const int_t MOVE_PRIORITY_END[DIR_MAXCOUNT] = { 1, 6, 6, 6, 6, 6, 6, 6, 6 };
}
