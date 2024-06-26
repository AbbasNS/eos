/* vim: set sw=4 sts=4 et foldmethod=syntax : */

/*
 * Copyright (c) 2010, 2011, 2017 Danny van Dyk
 * Copyright (c) 2010, 2011 Christian Wacker
 *
 * This file is part of the EOS project. EOS is free software;
 * you can redistribute it and/or modify it under the terms of the GNU General
 * Public License version 2, as published by the Free Software Foundation.
 *
 * EOS is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <test/test.hh>
#include <eos/rare-b-decays/charm-loops.hh>

#include <cmath>

using namespace test;
using namespace eos;

class OneLoopTest :
    public TestCase
{
    public:
        OneLoopTest() :
            TestCase("one_loop_test")
        {
        }

        virtual void run() const
        {
            /* Comparison with Christoph Bobeth's result from May 2010 */
            /* One-Loop h */
            {
                static const double mu = 4.2, s = 1.0, m_c = 1.4, m_b = 4.8, eps = 0.00001;
                TEST_CHECK_NEARLY_EQUAL(+1.57192, real(CharmLoops::h(mu, s)), eps);
                TEST_CHECK_NEARLY_EQUAL(+1.39626, imag(CharmLoops::h(mu, s)), eps);

                TEST_CHECK_NEARLY_EQUAL(+0.58013, CharmLoops::h(mu, s, m_c), eps);

                TEST_CHECK_NEARLY_EQUAL(-0.55926, CharmLoops::h(mu, s, m_b), eps);
            }

            /* One-Loop h, m = m_c, as a function of s, in interval around s = 0 */
            {
                static const double mu = 4.2, m_c = 1.4, eps = 0.00001;

                TEST_CHECK_NEARLY_EQUAL(+0.24674, real(CharmLoops::h(mu, -9.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.27049, real(CharmLoops::h(mu, -8.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.29564, real(CharmLoops::h(mu, -7.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.32236, real(CharmLoops::h(mu, -6.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.35086, real(CharmLoops::h(mu, -5.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.38141, real(CharmLoops::h(mu, -4.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.41433, real(CharmLoops::h(mu, -3.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.45003, real(CharmLoops::h(mu, -2.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.48906, real(CharmLoops::h(mu, -1.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.53210, real(CharmLoops::h(mu,  0.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.58014, real(CharmLoops::h(mu, +1.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.63454, real(CharmLoops::h(mu, +2.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.69738, real(CharmLoops::h(mu, +3.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.77198, real(CharmLoops::h(mu, +4.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+1.17626, real(CharmLoops::h(mu, +7.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+1.68173, real(CharmLoops::h(mu, +8.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+1.48786, real(CharmLoops::h(mu, +9.0, m_c)), eps);

                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::h(mu, -4.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::h(mu, -3.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::h(mu, -2.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::h(mu, -1.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::h(mu,  0.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::h(mu, +1.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::h(mu, +2.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::h(mu, +3.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::h(mu, +4.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.29422, imag(CharmLoops::h(mu, +8.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.71961, imag(CharmLoops::h(mu, +9.0, m_c)), eps);
            }

            /* One-Loop h, massless */
            {
                /* The imaginary part for massless h is always 4/9 Pi */
                static const double mu = 4.2, eps = 0.00001;

                TEST_CHECK_NEARLY_EQUAL(4.0 / 9.0 * M_PI, imag(CharmLoops::h(mu,  1.00)), eps);
                TEST_CHECK_NEARLY_EQUAL(4.0 / 9.0 * M_PI, imag(CharmLoops::h(mu,  6.00)), eps);
                TEST_CHECK_NEARLY_EQUAL(4.0 / 9.0 * M_PI, imag(CharmLoops::h(mu, 14.00)), eps);
                TEST_CHECK_NEARLY_EQUAL(4.0 / 9.0 * M_PI, imag(CharmLoops::h(mu, 19.21)), eps);
            }

            /* One-Loop B0, m = m_c */
            {
                static const double m_c = 1.4, eps = 0.00001;

                TEST_CHECK_NEARLY_EQUAL(-2.54698, real(CharmLoops::B0(-9.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-2.50056, real(CharmLoops::B0(-8.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-2.45159, real(CharmLoops::B0(-7.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-2.39975, real(CharmLoops::B0(-6.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-2.34468, real(CharmLoops::B0(-5.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-2.28592, real(CharmLoops::B0(-4.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-2.22288, real(CharmLoops::B0(-3.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-2.15488, real(CharmLoops::B0(-2.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-2.08099, real(CharmLoops::B0(-1.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-2.00000, real(CharmLoops::B0( 0.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.91028, real(CharmLoops::B0(+1.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.80952, real(CharmLoops::B0(+2.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.69427, real(CharmLoops::B0(+3.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.55906, real(CharmLoops::B0(+4.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-0.04026, real(CharmLoops::B0(+8.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-0.26980, real(CharmLoops::B0(+9.0, m_c)), eps);

                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::B0(-4.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::B0(-3.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::B0(-2.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::B0(-1.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::B0( 0.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::B0(+1.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::B0(+2.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::B0(+3.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.0,     imag(CharmLoops::B0(+4.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.44429, imag(CharmLoops::B0(+8.0, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+1.12787, imag(CharmLoops::B0(+9.0, m_c)), eps);
            }
        }
} one_loop_test;

class HelperTest :
    public TestCase
{
    public:
        HelperTest() :
            TestCase("helper_test")
        {
        }

        virtual void run() const
        {
            /* Comparison with Mathematica results from July 2010 */

            /* C0 */
            {
                static const double m_b = 4.45, s_one = m_b * m_b, eps = 0.000001;
                // real parts
                TEST_CHECK_NEARLY_EQUAL(-1.64493406685, real(CharmLoops::C0( 0.0,  m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.648607,      real(CharmLoops::C0( 0.5,  m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.652304,      real(CharmLoops::C0( 1.0,  m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.659779,      real(CharmLoops::C0( 2.0,  m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.667360,      real(CharmLoops::C0( 3.0,  m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.690774,      real(CharmLoops::C0( 6.0,  m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.715257,      real(CharmLoops::C0( 9.0,  m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.740899,      real(CharmLoops::C0(12.0,  m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.767803,      real(CharmLoops::C0(15.0,  m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.796088,      real(CharmLoops::C0(18.0,  m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.807916,      real(CharmLoops::C0(19.21, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.813774,      real(CharmLoops::C0(19.80, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.813799364,   real(CharmLoops::C0(s_one, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.813874,      real(CharmLoops::C0(19.81, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.815774,      real(CharmLoops::C0(20.0,  m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.825884,      real(CharmLoops::C0(21.0,  m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.836178,      real(CharmLoops::C0(22.0,  m_b)), eps);

                // imag parts
                TEST_CHECK_NEARLY_EQUAL(+0.000000000,  imag(CharmLoops::C0( 1.0, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.000000000,  imag(CharmLoops::C0( 6.0, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.000000000,  imag(CharmLoops::C0(11.0, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.000000000,  imag(CharmLoops::C0(16.0, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.000000000,  imag(CharmLoops::C0(19.0, m_b)), eps);
            }
        }
} helper_test;

class SeidelFunctionTest :
    public TestCase
{
    public:
        SeidelFunctionTest() :
            TestCase("seidel_function_test")
        {
        }

        virtual void run() const
        {
            /* Comparison with Mathematica results */
            {
                static const double eps = 1e-7;
                static const double mu  = 4.2;
                static const double m_b = 4.6;

                // CharmLoops::A
                TEST_CHECK_NEARLY_EQUAL(0.9773295847097823, real(CharmLoops::A(mu, 0.1   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.9214363985136449, real(CharmLoops::A(mu, 0.2   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8763703269301939, real(CharmLoops::A(mu, 0.3   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8378238727298053, real(CharmLoops::A(mu, 0.4   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8038113953761623, real(CharmLoops::A(mu, 0.5   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.7731991760882022, real(CharmLoops::A(mu, 0.6   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.7452609937428958, real(CharmLoops::A(mu, 0.7   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.7194961842495493, real(CharmLoops::A(mu, 0.8   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.6955413360449034, real(CharmLoops::A(mu, 0.9   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.6755202491234607, real(CharmLoops::A(mu, 0.989 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.6750830687385123, real(CharmLoops::A(mu, 0.991 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.6733396774972732, real(CharmLoops::A(mu, 0.999 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.6731223501151583, real(CharmLoops::A(mu, 1.0   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.6729051546645827, real(CharmLoops::A(mu, 1.001 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.6711723181761371, real(CharmLoops::A(mu, 1.009 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.6707404153377090, real(CharmLoops::A(mu, 1.011 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.6520262388101052, real(CharmLoops::A(mu, 1.1   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.6320834983833805, real(CharmLoops::A(mu, 1.2   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.6131565526952305, real(CharmLoops::A(mu, 1.3   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.595131879233407,  real(CharmLoops::A(mu, 1.4   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.5779144700352841, real(CharmLoops::A(mu, 1.5   * m_b * m_b, m_b)), eps);

                TEST_CHECK_NEARLY_EQUAL(0.6146283866916408, imag(CharmLoops::A(mu, 0.1   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.6636082140569280, imag(CharmLoops::A(mu, 0.2   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.6989293588461240, imag(CharmLoops::A(mu, 0.3   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.7267965974570413, imag(CharmLoops::A(mu, 0.4   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.7498451601160822, imag(CharmLoops::A(mu, 0.5   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.7694868420677202, imag(CharmLoops::A(mu, 0.6   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.7865792246366115, imag(CharmLoops::A(mu, 0.7   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8016869872542616, imag(CharmLoops::A(mu, 0.8   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8152036571681478, imag(CharmLoops::A(mu, 0.9   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8261288291878165, imag(CharmLoops::A(mu, 0.989 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8263637305615362, imag(CharmLoops::A(mu, 0.991 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8272989394799615, imag(CharmLoops::A(mu, 0.999 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8274153490936081, imag(CharmLoops::A(mu, 1.0   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8275316501089502, imag(CharmLoops::A(mu, 1.001 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8284581709044996, imag(CharmLoops::A(mu, 1.009 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8286887280252740, imag(CharmLoops::A(mu, 1.011 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8385370486103412, imag(CharmLoops::A(mu, 1.1   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8487346187930029, imag(CharmLoops::A(mu, 1.2   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8581388308167810, imag(CharmLoops::A(mu, 1.3   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8668546781765816, imag(CharmLoops::A(mu, 1.4   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(0.8749677701646030, imag(CharmLoops::A(mu, 1.5   * m_b * m_b, m_b)), eps);
            }

            {
                static const double eps = 5e-7;
                static const double mu  = 4.2;
                static const double m_b = 4.6;

                // CharmLoops::B
                // compare with results from Mathematica
                TEST_CHECK_NEARLY_EQUAL( 1.774836109825061, real(CharmLoops::B(mu, 0.1    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 0.660841461662527, real(CharmLoops::B(mu, 0.2    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 0.054907084216395, real(CharmLoops::B(mu, 0.3    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-0.349267491647551, real(CharmLoops::B(mu, 0.4    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-0.645893534420443, real(CharmLoops::B(mu, 0.5    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-0.876221241512994, real(CharmLoops::B(mu, 0.6    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.061898918819812, real(CharmLoops::B(mu, 0.7    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.215647742767820, real(CharmLoops::B(mu, 0.8    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.345549747764342, real(CharmLoops::B(mu, 0.9    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.445551305876865, real(CharmLoops::B(mu, 0.989  * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.447653911549639, real(CharmLoops::B(mu, 0.991  * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.456005423324896, real(CharmLoops::B(mu, 0.999  * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.457042788460703, real(CharmLoops::B(mu, 1.0    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.458078703478798, real(CharmLoops::B(mu, 1.001  * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.466314200418869, real(CharmLoops::B(mu, 1.009  * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.468358794660238, real(CharmLoops::B(mu, 1.011  * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.553950465199060, real(CharmLoops::B(mu, 1.1    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.639057020304387, real(CharmLoops::B(mu, 1.2    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.714448422091565, real(CharmLoops::B(mu, 1.3    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.781724905891100, real(CharmLoops::B(mu, 1.4    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.842138876544684, real(CharmLoops::B(mu, 1.5    * m_b * m_b, m_b)), eps);

                TEST_CHECK_NEARLY_EQUAL( 5.553840794326391, imag(CharmLoops::B(mu, 0.1    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 4.820249145955325, imag(CharmLoops::B(mu, 0.2    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 4.360108135584585, imag(CharmLoops::B(mu, 0.3    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 4.017944023522331, imag(CharmLoops::B(mu, 0.4    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 3.743067928416354, imag(CharmLoops::B(mu, 0.5    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 3.512167767255114, imag(CharmLoops::B(mu, 0.6    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 3.312463519105912, imag(CharmLoops::B(mu, 0.7    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 3.136141749913582, imag(CharmLoops::B(mu, 0.8    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 2.978054117771269, imag(CharmLoops::B(mu, 0.9    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 2.849764927794023, imag(CharmLoops::B(mu, 0.989  * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 2.846999895193758, imag(CharmLoops::B(mu, 0.991  * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 2.835988381444127, imag(CharmLoops::B(mu, 0.999  * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 2.834617374526911, imag(CharmLoops::B(mu, 1.0    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 2.833247567362475, imag(CharmLoops::B(mu, 1.001  * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 2.822332037234379, imag(CharmLoops::B(mu, 1.009  * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 2.819614998962907, imag(CharmLoops::B(mu, 1.011  * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 2.703230935969235, imag(CharmLoops::B(mu, 1.1    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 2.581943911053763, imag(CharmLoops::B(mu, 1.2    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 2.469253015913550, imag(CharmLoops::B(mu, 1.3    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 2.363973892039418, imag(CharmLoops::B(mu, 1.4    * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 2.265155869018138, imag(CharmLoops::B(mu, 1.5    * m_b * m_b, m_b)), eps);
            }
        }
} seidel_function_test;


class FormFactorsTest :
    public TestCase
{
    public:
        FormFactorsTest() :
            TestCase("form_factors_test")
        {
        }

        virtual void run() const
        {
            /* Comparison with Christoph Bobeth's result from May 2010 */

            /* Formfactors, massless loops */
            {
                static const double mu = 4.2, s = 6.0, m_b = 4.6, eps = 0.0000001;
                TEST_CHECK_NEARLY_EQUAL(- 0.8832611, real(CharmLoops::F17_massless(mu, s, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(- 0.6937322, imag(CharmLoops::F17_massless(mu, s, m_b)), eps);

                TEST_CHECK_NEARLY_EQUAL(+ 5.2995666, real(CharmLoops::F27_massless(mu, s, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(+ 4.1623936, imag(CharmLoops::F27_massless(mu, s, m_b)), eps);

                TEST_CHECK_NEARLY_EQUAL(+ 3.3632062, real(CharmLoops::F19_massless(mu, s, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(- 6.9078480, imag(CharmLoops::F19_massless(mu, s, m_b)), eps);

                TEST_CHECK_NEARLY_EQUAL(+ 3.4455298, real(CharmLoops::F29_massless(mu, s, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(+24.6919276, imag(CharmLoops::F29_massless(mu, s, m_b)), eps);

                TEST_CHECK_NEARLY_EQUAL(- 1.2486221, real(CharmLoops::F87_massless(mu, s, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(- 2.7925269, imag(CharmLoops::F87_massless(mu, s, m_b)), eps);

                TEST_CHECK_NEARLY_EQUAL(- 3.2730189, real(CharmLoops::F89_massless(s, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(  0.0000000, imag(CharmLoops::F89_massless(s, m_b)), eps);
            }

            /* Formfactors for O_8 are problematic near the zero recoil point */
            {
                static const double mu = 4.2, s = 19.2, m_b = 4.6, eps = 0.0000001;

                TEST_CHECK_NEARLY_EQUAL(- 0.9708796,  real(CharmLoops::F87_massless(mu, s, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(- 2.7925268,  imag(CharmLoops::F87_massless(mu, s, m_b)), eps);

                TEST_CHECK_NEARLY_EQUAL(- 2.0208146,  real(CharmLoops::F89_massless(s, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(  0.0000000,  imag(CharmLoops::F89_massless(s, m_b)), eps);
            }

            /* Check imaginary parts of the form factors at the boundaries of the Low Recoil region */
            {
                static const double mu = 4.2, s1 = 14.0, s2 = 19.2, m_b = 4.6, eps = 0.0000001;

                TEST_CHECK_NEARLY_EQUAL(+0.7802809, imag(CharmLoops::A(mu, s1, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(+0.8161455, imag(CharmLoops::A(mu, s2, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-2.7925268, imag(CharmLoops::F87_massless(mu, s1, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-2.7925268, imag(CharmLoops::F87_massless(mu, s2, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-5.8682288, imag(CharmLoops::F19_massless(mu, s1, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-5.4492617, imag(CharmLoops::F19_massless(mu, s2, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(18.4542117, imag(CharmLoops::F29_massless(mu, s1, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(15.9404096, imag(CharmLoops::F29_massless(mu, s2, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 0.0000000, imag(CharmLoops::F89_massless(s1, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL( 0.0000000, imag(CharmLoops::F89_massless(s2, m_b)), eps);
            }

            /* Check F87_massless and F89_massless near s_hat = 1 */
            {
                static const double mu = 4.2, m_b = 4.6, eps = 6e-7;

                TEST_CHECK_NEARLY_EQUAL(-0.951276751910152, real(CharmLoops::F87_massless(mu, 0.989 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-0.950828012015162, real(CharmLoops::F87_massless(mu, 0.991 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-0.949047612614735, real(CharmLoops::F87_massless(mu, 0.999 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-0.948826693927197, real(CharmLoops::F87_massless(mu, 1.0   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-0.948606136377817, real(CharmLoops::F87_massless(mu, 1.001 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-0.946854628625707, real(CharmLoops::F87_massless(mu, 1.009 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-0.946420334996110, real(CharmLoops::F87_massless(mu, 1.011 * m_b * m_b, m_b)), eps);

                TEST_CHECK_NEARLY_EQUAL(-2.792526803190927, imag(CharmLoops::F87_massless(mu, 0.989 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-2.792526803190927, imag(CharmLoops::F87_massless(mu, 0.991 * m_b * m_b, m_b)), eps);

                TEST_CHECK_NEARLY_EQUAL(-1.944265886425612, real(CharmLoops::F89_massless(0.989 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.942498970870095, real(CharmLoops::F89_massless(0.991 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.935479699592446, real(CharmLoops::F89_massless(0.999 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.934607689969977, real(CharmLoops::F89_massless(1.0   * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.933736871247196, real(CharmLoops::F89_massless(1.001 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.926812876524436, real(CharmLoops::F89_massless(1.009 * m_b * m_b, m_b)), eps);
                TEST_CHECK_NEARLY_EQUAL(-1.925093602661525, real(CharmLoops::F89_massless(1.011 * m_b * m_b, m_b)), eps);
            }

            /* Formfactors, massive loops at timelike s/q^2 */
            {
                static const double mu = 4.2, s = 6.0, m_b = 4.6, m_c = 1.2, eps = 1e-7;
                TEST_CHECK_NEARLY_EQUAL(- 0.73093991, real(CharmLoops::F17_massive(mu, s, m_b, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(- 0.17771334, imag(CharmLoops::F17_massive(mu, s, m_b, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+ 4.38563254, real(CharmLoops::F27_massive(mu, s, m_b, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+ 1.06627403, imag(CharmLoops::F27_massive(mu, s, m_b, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(-34.40870331, real(CharmLoops::F19_massive(mu, s, m_b, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(- 0.25864665, imag(CharmLoops::F19_massive(mu, s, m_b, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+ 6.27364439, real(CharmLoops::F29_massive(mu, s, m_b, m_c)), eps);
                TEST_CHECK_NEARLY_EQUAL(+ 1.55195807, imag(CharmLoops::F29_massive(mu, s, m_b, m_c)), eps);
            }

            /* Formfactors, massive loops at spacelike s/q^2 */
            {
                static const double mu = 4.2, m_b = 4.6, m_c = 1.2, eps = 1e-5;

                TEST_CHECK_RELATIVE_ERROR(- 0.5851990,  real(CharmLoops::F17_massive(mu, -6.0, m_b, m_c)), eps);
                TEST_CHECK_RELATIVE_ERROR(- 0.0622661,  imag(CharmLoops::F17_massive(mu, -6.0, m_b, m_c)), eps);
                TEST_CHECK_RELATIVE_ERROR(- 0.6507510,  real(CharmLoops::F17_massive(mu, -1.0, m_b, m_c)), eps);
                TEST_CHECK_RELATIVE_ERROR(- 0.0921000,  imag(CharmLoops::F17_massive(mu, -1.0, m_b, m_c)), eps);

                TEST_CHECK_RELATIVE_ERROR(+ 3.5112500,  real(CharmLoops::F27_massive(mu, -6.0, m_b, m_c)), eps);
                TEST_CHECK_RELATIVE_ERROR(+ 0.3736050,  imag(CharmLoops::F27_massive(mu, -6.0, m_b, m_c)), eps);
                TEST_CHECK_RELATIVE_ERROR(+ 3.9045200,  real(CharmLoops::F27_massive(mu, -1.0, m_b, m_c)), eps);
                TEST_CHECK_RELATIVE_ERROR(+ 0.5526040,  imag(CharmLoops::F27_massive(mu, -1.0, m_b, m_c)), eps);

                TEST_CHECK_RELATIVE_ERROR(- 3.2450800,  real(CharmLoops::F19_massive(mu, -6.0, m_b, m_c)), eps);
                TEST_CHECK_RELATIVE_ERROR(+ 0.1208170,  imag(CharmLoops::F19_massive(mu, -6.0, m_b, m_c)), eps);
                TEST_CHECK_RELATIVE_ERROR(-10.1066000,  real(CharmLoops::F19_massive(mu, -1.0, m_b, m_c)), eps);
                TEST_CHECK_RELATIVE_ERROR(+ 0.1100320,  imag(CharmLoops::F19_massive(mu, -1.0, m_b, m_c)), eps);

                TEST_CHECK_RELATIVE_ERROR(+ 4.4729700,  real(CharmLoops::F29_massive(mu, -6.0, m_b, m_c)), eps);
                TEST_CHECK_RELATIVE_ERROR(- 0.7247960,  imag(CharmLoops::F29_massive(mu, -6.0, m_b, m_c)), eps);
                TEST_CHECK_RELATIVE_ERROR(+ 4.0282600,  real(CharmLoops::F29_massive(mu, -1.0, m_b, m_c)), eps);
                TEST_CHECK_RELATIVE_ERROR(- 0.6601020,  imag(CharmLoops::F29_massive(mu, -1.0, m_b, m_c)), eps);
            }
        }
} two_loop_test;

class LowRecoilTest :
    public TestCase
{
    public:
        LowRecoilTest() :
            TestCase("low_recoil_test")
        {
        }

        virtual void run() const
        {
            using std::imag;
            using std::real;

            /* Comparison with Stefan Meinel from September 2019 */

            Parameters p  = Parameters::Defaults();
            auto       m  = Model::make("WET", p, Options());

            {
                static const double mu = 4.2, s = 15.0, eps = 1e-2;
                const double        alpha_s = m->alpha_s(mu);
                const double        m_b_PS = m->m_b_ps(2.0);
                const auto          m_c = m->m_c_msbar(mu);
                const auto          wc = m->wilson_coefficients_b_to_s(mu, "mu", false);

                TEST_CHECK_NEARLY_EQUAL( 4.46, m_b_PS,         eps);

                const auto c7eff = ShortDistanceLowRecoil::c7eff(s, mu, alpha_s, m_b_PS, true, wc);
                TEST_CHECK_NEARLY_EQUAL(-0.39, real(c7eff),    eps);
                TEST_CHECK_NEARLY_EQUAL(-0.10, imag(c7eff),    eps);

                const auto c9eff = ShortDistanceLowRecoil::c9eff(s, mu, alpha_s, m_b_PS, m_c, true, false, 0.0, wc);
                TEST_CHECK_NEARLY_EQUAL(+4.66, real(c9eff),    eps);
                TEST_CHECK_NEARLY_EQUAL( 0.55, imag(c9eff),    eps);
            }
        }
} low_recoil_test;


class CharmlessTest :
    public TestCase
{
    public:
        CharmlessTest() :
            TestCase("charmless_test")
        {
        }

        virtual void run() const
        {
            using std::imag;
            using std::real;

            /* Test cubic spline interpolation by comparison with Javier Virto's notebook */
            {

                static const double eps = 1e-3;

                TEST_CHECK_NEARLY_EQUAL(real(CharmLoops::F17_massive_Qsb(2.0)), -0.0715022,    eps);
                TEST_CHECK_NEARLY_EQUAL(imag(CharmLoops::F17_massive_Qsb(2.0)), -0.00894292,   eps);
                TEST_CHECK_NEARLY_EQUAL(real(CharmLoops::F19_massive_Qsb(2.0)),  0.195383,     eps);
                TEST_CHECK_NEARLY_EQUAL(imag(CharmLoops::F19_massive_Qsb(2.0)),  0.25814,      eps);
                TEST_CHECK_NEARLY_EQUAL(real(CharmLoops::F27_massive_Qsb(2.0)),  0.429013,     eps);
                TEST_CHECK_NEARLY_EQUAL(imag(CharmLoops::F27_massive_Qsb(2.0)),  0.0536575,    eps);
                TEST_CHECK_NEARLY_EQUAL(real(CharmLoops::F29_massive_Qsb(2.0)), -1.1723,       eps);
                TEST_CHECK_NEARLY_EQUAL(imag(CharmLoops::F29_massive_Qsb(2.0)), -1.54884,      eps);

                TEST_CHECK_NEARLY_EQUAL(real(CharmLoops::F17_massive_Qsb(8.0)), -0.0683473,    eps);
                TEST_CHECK_NEARLY_EQUAL(imag(CharmLoops::F17_massive_Qsb(8.0)), -0.0153357,    eps);
                TEST_CHECK_NEARLY_EQUAL(real(CharmLoops::F19_massive_Qsb(8.0)),  0.102639,     eps);
                TEST_CHECK_NEARLY_EQUAL(imag(CharmLoops::F19_massive_Qsb(8.0)),  0.191314,     eps);
                TEST_CHECK_NEARLY_EQUAL(real(CharmLoops::F27_massive_Qsb(8.0)),  0.410084,     eps);
                TEST_CHECK_NEARLY_EQUAL(imag(CharmLoops::F27_massive_Qsb(8.0)),  0.0920144,    eps);
                TEST_CHECK_NEARLY_EQUAL(real(CharmLoops::F29_massive_Qsb(8.0)), -0.615832,     eps);
                TEST_CHECK_NEARLY_EQUAL(imag(CharmLoops::F29_massive_Qsb(8.0)), -1.14788,      eps);

            }
        }
} charmless_test;
