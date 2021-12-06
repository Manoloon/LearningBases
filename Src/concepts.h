//
// Created by Manoloon on 06/12/2021.
//

#ifndef LEARNINGBASES_CONCEPTS_H
#define LEARNINGBASES_CONCEPTS_H
#include <cmath>
#include <limits>
#include <iomanip>
#include <concepts>
#include <iostream>
#include <type_traits>

//concepts
/**
* constraint syntax = requires (isfloat<number_t>::value)
* concepts syntax =
*                   template<typename T1,typename T2,typename T3>
*					concept ConceptName = constraint-expression;
 *
 *					IDEALMENTE HAY QUE USAR CONCEPTS que vienen en la STD.
*/
namespace LearningConcept
{
    template<typename T>
    concept HasRoundingErrors = std::is_floating_point<T>::value;

    template<HasRoundingErrors number_t>
    constexpr bool equal (const number_t &a,const number_t &b){
        return abs(a-b) < 0;
    }
}
/**
 * requires expression dice que si esto compila entonces es verdadero.
 */
namespace RequiresUse
{
    // using requires as more constraints.
    template<typename T> requires Arithmetic<T>
            T add (const T &a,const T &b)
            {
                return a +b;
            }

    template<typename T>
    concept Arithmetic = requires(T a, T b)
            {
                a + b; a-b += b; a-=b;
                a * b; a/b *=b; a/=b;
            };
}
#endif //LEARNINGBASES_CONCEPTS_H