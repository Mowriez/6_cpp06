/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:44:48 by mtrautne          #+#    #+#             */
/*   Updated: 2023/12/04 20:44:48 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base *	generate() {
	int seed = std::clock();
	std::srand (seed);
	int random_value = std::rand() % 3;
	if (random_value == 0) {
		std::cout << "A created" << std::endl;
		return (new A);
	}
	else if (random_value == 1) {
		std::cout << "B created" << std::endl;
		return (new B);
	}
	else {
		std::cout << "C created" << std::endl;
		return (new C);
	}
}

void	Base::identify(Base &p) {
	try {
		dynamic_cast<A&>(p);
		dynamic_cast<B&>(p);
		dynamic_cast<C&>(p);
	}
	catch
}

void	Base::identify(Base *p) {

}

int	main(void) {
	Base* a = generate();
	Base* b = generate();
	Base* c = generate();
	Base* d = generate();
	delete a;
	delete b;
	delete c;
	delete d;
}
