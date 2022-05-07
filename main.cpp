#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;


class LightSignal {
	protected:
		int state;
	public:
		static const int STOP = 0;
		static const int ORANGE_LIGHT = 1;
		static const int RED_LIGHT = 2;
		static const int GREEN_LIGHT = 3;
		static const int NUMBER_OF_STATES = 4;
		LightSignal() {
			state = STOP;
		}
		void changeState() {
			state = (state + 1) % NUMBER_OF_STATES;

		}
		int getState() {
			return state;
		}
		string getMessage() {
			switch (state) {
				case STOP: return "STOP";
				case ORANGE_LIGHT: return "ORANGE_LIGHT";
				case RED_LIGHT: return "RED_LIGHT";
				case GREEN_LIGHT: return "GREEN LIGHT";
				default: return "ILLEGAL STATE";
			}
		}
	
};

class Light : public LightSignal {
	public:
		string getMessage();

    Light(int s) {
      if (s >=0 && s <=3) {
        this->state = s;
      }
      else throw("No se puede");
    }
};



class ControlSystem {
  protected:
		static ControlSystem *instance;
		vector<Light*> lights;
    ControlSystem() {
      for (int i=0; i<4; i++) {
        Light* l = new Light(i);
        lights.push_back(l);
      }
    }

    ~ControlSystem();

  
  public:
    static ControlSystem *getInstance() {
			if (!instance)
				instance = new ControlSystem();
			return instance;
    }
};


int main() {
		LightSignal* t1 = new LightSignal;
		for (int i = 0; i < 4; i++) {
			cout << t1->getMessage() << endl;
			t1->changeState();
		}
    return 0;
}

