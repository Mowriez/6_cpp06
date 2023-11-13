/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:22:30 by mtrautne          #+#    #+#             */
/*   Updated: 2023/11/11 18:22:30 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

class WrongArgumentNumException : public std::exception {
	const char*	what() const throw();
};
