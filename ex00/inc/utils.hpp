/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrautne <mtrautne@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:35:00 by mtrautne          #+#    #+#             */
/*   Updated: 2023/11/13 14:35:00 by mtrautne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_CPP
# define UTILS_CPP

# include <string>
# include <cctype>
# include <iostream>

enum	InputType{CHAR, INT, FLOAT, DOUBLE, UNKNOWN};

InputType	checkType(std::string& input);
bool		isOnlyNumerical(std::string& input);
bool		preCheckValid(std::string& input);

#endif
