/*
 * mbsolve: Framework for solving the Maxwell-Bloch/-Lioville equations
 *
 * Copyright (c) 2016, Computational Photonics Group, Technical University of
 * Munich.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

#ifndef MBSOLVE_SOLVER_H
#define MBSOLVE_SOLVER_H

#include <map>
#include <memory>
#include <string>
#include <vector>
#include <device.hpp>
#include <internal/solver_int.hpp>
#include <scenario.hpp>
#include <types.hpp>

namespace mbsolve {

/**
 * This class provides the interface to create an instance of a solver
 * implementation. Each implementation is a subclass of \ref solver_int and
 * is created internally.
 * \ingroup MBSOLVE_LIB
 */
class solver
{
private:
    std::shared_ptr<solver_int> m_solver;

public:
    /**
     * Constructs solver with a given \p name.
     *
     * \param [in] name Name of the solver method.
     * \param [in] dev  Specify the \ref device to be simulated.
     * \param [in] scen Specify the \ref scenario.
     */
    solver(const std::string& name, std::shared_ptr<const device> dev,
	   std::shared_ptr<scenario> scen);

    ~solver();

    /**
     * Gets solver name.
     */
    const std::string& get_name() const;

    /**
     * Gets scenario.
     */
    const scenario& get_scenario() const { return m_solver->get_scenario(); }

    /**
     * Gets device.
     */
    const device& get_device() const { return m_solver->get_device(); }

    /**
     * Executes the solver.
     */
    void run() const;

    /**
     * Gets results.
     */
    const std::vector<std::shared_ptr<result> >& get_results() const;

};

}

#endif
