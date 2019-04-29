
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.18.0

#include <stan/model/model_header.hpp>

namespace model_Weibull_NPH_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_Weibull_NPH");
    reader.add_event(28, 26, "end", "model_Weibull_NPH");
    return reader;
}

class model_Weibull_NPH : public prob_grad {
private:
    int N;
    vector<double> y;
    vector<double> z;
    vector<int> nu;
public:
    model_Weibull_NPH(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_Weibull_NPH(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_Weibull_NPH_namespace::model_Weibull_NPH";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            validate_non_negative_index("y", "N", N);
            context__.validate_dims("data initialization", "y", "double", context__.to_vec(N));
            validate_non_negative_index("y", "N", N);
            y = std::vector<double>(N,double(0));
            vals_r__ = context__.vals_r("y");
            pos__ = 0;
            size_t y_limit_0__ = N;
            for (size_t i_0__ = 0; i_0__ < y_limit_0__; ++i_0__) {
                y[i_0__] = vals_r__[pos__++];
            }
            validate_non_negative_index("z", "N", N);
            context__.validate_dims("data initialization", "z", "double", context__.to_vec(N));
            validate_non_negative_index("z", "N", N);
            z = std::vector<double>(N,double(0));
            vals_r__ = context__.vals_r("z");
            pos__ = 0;
            size_t z_limit_0__ = N;
            for (size_t i_0__ = 0; i_0__ < z_limit_0__; ++i_0__) {
                z[i_0__] = vals_r__[pos__++];
            }
            validate_non_negative_index("nu", "N", N);
            context__.validate_dims("data initialization", "nu", "int", context__.to_vec(N));
            validate_non_negative_index("nu", "N", N);
            nu = std::vector<int>(N,int(0));
            vals_i__ = context__.vals_i("nu");
            pos__ = 0;
            size_t nu_limit_0__ = N;
            for (size_t i_0__ = 0; i_0__ < nu_limit_0__; ++i_0__) {
                nu[i_0__] = vals_i__[pos__++];
            }

            // validate, data variables
            for (int k0__ = 0; k0__ < N; ++k0__) {
                check_greater_or_equal(function__,"y[k0__]",y[k0__],0);
            }
            for (int k0__ = 0; k0__ < N; ++k0__) {
                check_greater_or_equal(function__,"z[k0__]",z[k0__],0);
                check_less_or_equal(function__,"z[k0__]",z[k0__],1);
            }
            for (int k0__ = 0; k0__ < N; ++k0__) {
                check_greater_or_equal(function__,"nu[k0__]",nu[k0__],0);
                check_less_or_equal(function__,"nu[k0__]",nu[k0__],1);
            }
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            ++num_params_r__;
            ++num_params_r__;
            ++num_params_r__;
            ++num_params_r__;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_Weibull_NPH() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("alpha1")))
            throw std::runtime_error("variable alpha1 missing");
        vals_r__ = context__.vals_r("alpha1");
        pos__ = 0U;
        context__.validate_dims("initialization", "alpha1", "double", context__.to_vec());
        double alpha1(0);
        alpha1 = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,alpha1);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable alpha1: ") + e.what());
        }

        if (!(context__.contains_r("alpha2")))
            throw std::runtime_error("variable alpha2 missing");
        vals_r__ = context__.vals_r("alpha2");
        pos__ = 0U;
        context__.validate_dims("initialization", "alpha2", "double", context__.to_vec());
        double alpha2(0);
        alpha2 = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,alpha2);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable alpha2: ") + e.what());
        }

        if (!(context__.contains_r("theta1")))
            throw std::runtime_error("variable theta1 missing");
        vals_r__ = context__.vals_r("theta1");
        pos__ = 0U;
        context__.validate_dims("initialization", "theta1", "double", context__.to_vec());
        double theta1(0);
        theta1 = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(theta1);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable theta1: ") + e.what());
        }

        if (!(context__.contains_r("theta2")))
            throw std::runtime_error("variable theta2 missing");
        vals_r__ = context__.vals_r("theta2");
        pos__ = 0U;
        context__.validate_dims("initialization", "theta2", "double", context__.to_vec());
        double theta2(0);
        theta2 = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(theta2);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable theta2: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        try {
            // model parameters
            stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);

            local_scalar_t__ alpha1;
            (void) alpha1;  // dummy to suppress unused var warning
            if (jacobian__)
                alpha1 = in__.scalar_lb_constrain(0,lp__);
            else
                alpha1 = in__.scalar_lb_constrain(0);

            local_scalar_t__ alpha2;
            (void) alpha2;  // dummy to suppress unused var warning
            if (jacobian__)
                alpha2 = in__.scalar_lb_constrain(0,lp__);
            else
                alpha2 = in__.scalar_lb_constrain(0);

            local_scalar_t__ theta1;
            (void) theta1;  // dummy to suppress unused var warning
            if (jacobian__)
                theta1 = in__.scalar_constrain(lp__);
            else
                theta1 = in__.scalar_constrain();

            local_scalar_t__ theta2;
            (void) theta2;  // dummy to suppress unused var warning
            if (jacobian__)
                theta2 = in__.scalar_constrain(lp__);
            else
                theta2 = in__.scalar_constrain();


            // transformed parameters



            // validate transformed parameters

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            // model body

            lp_accum__.add(normal_log<propto__>(alpha1, 0, 100));
            lp_accum__.add(normal_log<propto__>(alpha2, 0, 100));
            lp_accum__.add(normal_log<propto__>(theta1, 0, 100));
            lp_accum__.add(normal_log<propto__>(theta2, 0, 100));
            for (int n = 1; n <= N; ++n) {
                {
                local_scalar_t__ alpha;
                (void) alpha;  // dummy to suppress unused var warning

                stan::math::initialize(alpha, DUMMY_VAR__);
                stan::math::fill(alpha,DUMMY_VAR__);
                stan::math::assign(alpha,(((1 - get_base1(z,n,"z",1)) * alpha1) + (get_base1(z,n,"z",1) * alpha2)));
                local_scalar_t__ lambda;
                (void) lambda;  // dummy to suppress unused var warning

                stan::math::initialize(lambda, DUMMY_VAR__);
                stan::math::fill(lambda,DUMMY_VAR__);
                stan::math::assign(lambda,(((1 - get_base1(z,n,"z",1)) * theta1) + (get_base1(z,n,"z",1) * theta2)));


                if (as_bool(logical_eq(get_base1(nu,n,"nu",1),1))) {
                    lp_accum__.add(weibull_log<propto__>(get_base1(y,n,"y",1), alpha, stan::math::exp((-(lambda) / alpha))));
                } else {
                    lp_accum__.add(weibull_ccdf_log(get_base1(y,n,"y",1),alpha,stan::math::exp((-(lambda) / alpha))));
                }
                }
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("alpha1");
        names__.push_back("alpha2");
        names__.push_back("theta1");
        names__.push_back("theta2");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);
        static const char* function__ = "model_Weibull_NPH_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        double alpha1 = in__.scalar_lb_constrain(0);
        double alpha2 = in__.scalar_lb_constrain(0);
        double theta1 = in__.scalar_constrain();
        double theta2 = in__.scalar_constrain();
        vars__.push_back(alpha1);
        vars__.push_back(alpha2);
        vars__.push_back(theta1);
        vars__.push_back(theta2);

        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {



            // validate transformed parameters

            // write transformed parameters
            if (include_tparams__) {
            }
            if (!include_gqs__) return;
            // declare and define generated quantities



            // validate generated quantities

            // write generated quantities
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_Weibull_NPH";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha1";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha2";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "theta1";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "theta2";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }


        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha1";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha2";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "theta1";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "theta2";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
        }


        if (!include_gqs__) return;
    }

}; // model

}




// Code generated by Stan version 2.18.0

#include <stan/model/model_header.hpp>

namespace model_Weibull_PH_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_Weibull_PH");
    reader.add_event(27, 25, "end", "model_Weibull_PH");
    return reader;
}

class model_Weibull_PH : public prob_grad {
private:
    int N;
    vector<double> y;
    vector<double> z;
    vector<int> nu;
public:
    model_Weibull_PH(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_Weibull_PH(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_Weibull_PH_namespace::model_Weibull_PH";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            validate_non_negative_index("y", "N", N);
            context__.validate_dims("data initialization", "y", "double", context__.to_vec(N));
            validate_non_negative_index("y", "N", N);
            y = std::vector<double>(N,double(0));
            vals_r__ = context__.vals_r("y");
            pos__ = 0;
            size_t y_limit_0__ = N;
            for (size_t i_0__ = 0; i_0__ < y_limit_0__; ++i_0__) {
                y[i_0__] = vals_r__[pos__++];
            }
            validate_non_negative_index("z", "N", N);
            context__.validate_dims("data initialization", "z", "double", context__.to_vec(N));
            validate_non_negative_index("z", "N", N);
            z = std::vector<double>(N,double(0));
            vals_r__ = context__.vals_r("z");
            pos__ = 0;
            size_t z_limit_0__ = N;
            for (size_t i_0__ = 0; i_0__ < z_limit_0__; ++i_0__) {
                z[i_0__] = vals_r__[pos__++];
            }
            validate_non_negative_index("nu", "N", N);
            context__.validate_dims("data initialization", "nu", "int", context__.to_vec(N));
            validate_non_negative_index("nu", "N", N);
            nu = std::vector<int>(N,int(0));
            vals_i__ = context__.vals_i("nu");
            pos__ = 0;
            size_t nu_limit_0__ = N;
            for (size_t i_0__ = 0; i_0__ < nu_limit_0__; ++i_0__) {
                nu[i_0__] = vals_i__[pos__++];
            }

            // validate, data variables
            for (int k0__ = 0; k0__ < N; ++k0__) {
                check_greater_or_equal(function__,"y[k0__]",y[k0__],0);
            }
            for (int k0__ = 0; k0__ < N; ++k0__) {
                check_greater_or_equal(function__,"z[k0__]",z[k0__],0);
                check_less_or_equal(function__,"z[k0__]",z[k0__],1);
            }
            for (int k0__ = 0; k0__ < N; ++k0__) {
                check_greater_or_equal(function__,"nu[k0__]",nu[k0__],0);
                check_less_or_equal(function__,"nu[k0__]",nu[k0__],1);
            }
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            ++num_params_r__;
            ++num_params_r__;
            ++num_params_r__;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_Weibull_PH() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("alpha")))
            throw std::runtime_error("variable alpha missing");
        vals_r__ = context__.vals_r("alpha");
        pos__ = 0U;
        context__.validate_dims("initialization", "alpha", "double", context__.to_vec());
        double alpha(0);
        alpha = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,alpha);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable alpha: ") + e.what());
        }

        if (!(context__.contains_r("theta")))
            throw std::runtime_error("variable theta missing");
        vals_r__ = context__.vals_r("theta");
        pos__ = 0U;
        context__.validate_dims("initialization", "theta", "double", context__.to_vec());
        double theta(0);
        theta = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(theta);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable theta: ") + e.what());
        }

        if (!(context__.contains_r("delta")))
            throw std::runtime_error("variable delta missing");
        vals_r__ = context__.vals_r("delta");
        pos__ = 0U;
        context__.validate_dims("initialization", "delta", "double", context__.to_vec());
        double delta(0);
        delta = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(delta);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable delta: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        try {
            // model parameters
            stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);

            local_scalar_t__ alpha;
            (void) alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                alpha = in__.scalar_lb_constrain(0,lp__);
            else
                alpha = in__.scalar_lb_constrain(0);

            local_scalar_t__ theta;
            (void) theta;  // dummy to suppress unused var warning
            if (jacobian__)
                theta = in__.scalar_constrain(lp__);
            else
                theta = in__.scalar_constrain();

            local_scalar_t__ delta;
            (void) delta;  // dummy to suppress unused var warning
            if (jacobian__)
                delta = in__.scalar_constrain(lp__);
            else
                delta = in__.scalar_constrain();


            // transformed parameters
            validate_non_negative_index("lambda", "N", N);
            vector<local_scalar_t__> lambda(N);
            stan::math::initialize(lambda, DUMMY_VAR__);
            stan::math::fill(lambda,DUMMY_VAR__);


            for (int n = 1; n <= N; ++n) {
                stan::model::assign(lambda, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            (theta + (get_base1(z,n,"z",1) * delta)), 
                            "assigning variable lambda");
            }

            // validate transformed parameters
            for (int i0__ = 0; i0__ < N; ++i0__) {
                if (stan::math::is_uninitialized(lambda[i0__])) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: lambda" << '[' << i0__ << ']';
                    throw std::runtime_error(msg__.str());
                }
            }

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning

            // model body

            lp_accum__.add(normal_log<propto__>(alpha, 0, 100));
            lp_accum__.add(normal_log<propto__>(theta, 0, 100));
            for (int n = 1; n <= N; ++n) {

                if (as_bool(logical_eq(get_base1(nu,n,"nu",1),1))) {
                    lp_accum__.add(weibull_log<propto__>(get_base1(y,n,"y",1), alpha, stan::math::exp((-(get_base1(lambda,n,"lambda",1)) / alpha))));
                } else {
                    lp_accum__.add(weibull_ccdf_log(get_base1(y,n,"y",1),alpha,stan::math::exp((-(get_base1(lambda,n,"lambda",1)) / alpha))));
                }
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("alpha");
        names__.push_back("theta");
        names__.push_back("delta");
        names__.push_back("lambda");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);
        static const char* function__ = "model_Weibull_PH_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        double alpha = in__.scalar_lb_constrain(0);
        double theta = in__.scalar_constrain();
        double delta = in__.scalar_constrain();
        vars__.push_back(alpha);
        vars__.push_back(theta);
        vars__.push_back(delta);

        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            validate_non_negative_index("lambda", "N", N);
            vector<local_scalar_t__> lambda(N);
            stan::math::initialize(lambda, DUMMY_VAR__);
            stan::math::fill(lambda,DUMMY_VAR__);


            for (int n = 1; n <= N; ++n) {
                stan::model::assign(lambda, 
                            stan::model::cons_list(stan::model::index_uni(n), stan::model::nil_index_list()), 
                            (theta + (get_base1(z,n,"z",1) * delta)), 
                            "assigning variable lambda");
            }

            // validate transformed parameters

            // write transformed parameters
            if (include_tparams__) {
            for (int k_0__ = 0; k_0__ < N; ++k_0__) {
            vars__.push_back(lambda[k_0__]);
            }
            }
            if (!include_gqs__) return;
            // declare and define generated quantities



            // validate generated quantities

            // write generated quantities
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_Weibull_PH";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "theta";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "delta";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "lambda" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
        }


        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "theta";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "delta";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "lambda" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
        }


        if (!include_gqs__) return;
    }

}; // model

}




#endif
