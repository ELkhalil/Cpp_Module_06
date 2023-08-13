/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:58:47 by aelkhali          #+#    #+#             */
/*   Updated: 2023/08/12 16:58:48 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator

    for (int i = 0; i < 10; ++i) {
        Base* ptr = generate();
        identify(ptr);
        identify(*ptr);
        delete ptr;
    }

    return 0;
}
