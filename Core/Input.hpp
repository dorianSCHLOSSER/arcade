/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-quentin.pages
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

namespace Arcade {
    typedef enum {
		A_KEY,
		B_KEY,
		C_KEY,
		D_KEY,
		E_KEY,
		F_KEY,
		G_KEY,
		H_KEY,
		I_KEY,
		J_KEY,
		K_KEY,
		L_KEY,
		M_KEY,
		N_KEY,
		O_KEY,
		P_KEY,
		Q_KEY,
		R_KEY,
		S_KEY,
		T_KEY,
		U_KEY,
		V_KEY,
		W_KEY,
		X_KEY,
		Y_KEY,
		Z_KEY,
        NO_INPUT,
		ENTER,
		BACKSPACE,
		SPACE,
		ESCAPE,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		F2,
		F3,
		F4,
    } Input;

	typedef struct {
		int x;
		int y;
		std::string screenGame;
		std::string ncursesGame;
	} Pixel;
}

#endif /* !INPUT_HPP_ */
