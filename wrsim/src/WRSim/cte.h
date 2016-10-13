/***
 * Warthog Robotics
 * University of Sao Paulo (USP) at Sao Carlos
 * http://www.warthog.sc.usp.br/
 *
 * This file is part of WRSim project.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***/

#ifndef CTE_H
#define CTE_H


class cte{
public:
    cte();

    // constantes
    static constexpr int nProbes = 0; // para debug

    static constexpr double PI = 3.14159265358979;
    static constexpr double raiz2 = 1.4142135624;
    //    static const double larguraCampo = 1300; // mm
    //    static const double comprimentoCampo = 1500; // mm
};

#endif // CTE_H
