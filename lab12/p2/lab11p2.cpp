#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <set>
#include <queue>
#include <vector>

#include "State2.h"

class StateComparator {
 public:
  /* Determina algoritmul folosit. */
  enum Algorithm {
    AStar,
  };

  StateComparator(Algorithm algorithm)
      : algorithm_(algorithm) { }

  int f(State2* state) const{
    /* f(n) = g(n) + h(n) */
    /* g(n) = numarul de mutari din pozitia initiala */
    switch(algorithm_) {
      case AStar:
      return state->distance() + state->approx_distance();
    }
    return 0;
  }

  bool operator() (State2* State1, State2* State2) const {
    return f(State1) > f(State2);
  }

 private:
  const Algorithm algorithm_;
};

bool is_explored(std::vector<State2*>& closed, State2& state) {
  for (std::vector<State2*>::const_iterator it = closed.begin();
       it != closed.end();
       ++it) {
    if (state.has_same_state(**it)) {
      return true;
    }
  }
  return false;
}

bool getState(State2* state) {
    State2* s = NULL;	
    if(state->has_same_state(*s)) {
	return true;
    }
    return false;
}

void clearState(std::vector<State2*>& closed, State2* state) {
    auto it = std::find_if(closed.begin(), closed.end(), getState);
 
    if (it != closed.end()) {
        closed.erase(it);
    }
}

int main() {

  	State2* initial_State = new State2();
  	State2* solution_State = new State2();
  	
	initial_State->m_e = 3;
	initial_State->m_v = 0;
	initial_State->c_e = 3;
	initial_State->c_v = 0;
	initial_State->position = State2::E;

	solution_State->m_e = 0;
	solution_State->m_v = 3;
	solution_State->c_e = 0;
	solution_State->c_v = 3;
	solution_State->position = State2::V;

  	std::cout << "initial point " << *initial_State << std::endl;
  	std::cout << "final point " << *solution_State << std::endl;

	

  	/* Pentru nodurile in curs de explorare, implementate ca o coada de
   	* prioritati. */
  	std::priority_queue<State2*, std::vector<State2*>, StateComparator> open(
      	StateComparator(StateComparator::AStar));

  	/* Initial doar nodul de start este in curs de explorare. */
  	initial_State->set_distance(0);
  	initial_State->set_parent(NULL);
  	open.push(initial_State);

  	/* Pentru nodurile care au fost deja expandate. */
  	std::vector<State2*> closed;

	/* Numar de pasi pana la solutie */
	//int steps = 0;

	/*TODO: A* */
	State2 *crtState;
	std::vector<State2*> nextStates;

	closed.push_back(initial_State);

	while(!open.empty()) {
        	crtState = open.top();
        	open.pop();
        	nextStates.clear();

        	if(crtState->has_same_state(*solution_State)) {
            		crtState->print_path();
            		break;
        	}

        	crtState->expand(nextStates);
        	closed.push_back(crtState);

        	for(State2* s : nextStates) {
            		if(!is_explored(closed, *s)) {
                		s->set_distance(crtState->distance() + 1);
                		s->set_parent(crtState);
                		open.push(s);
            		} else if(crtState->distance() + 1 > s->distance()) {
                		clearState(closed, s);
                		s->set_distance(crtState->distance() + 1);
                		s->set_parent(crtState);
                		open.push(s);
            		}
        	}
	}
	
  	return 0;
}
