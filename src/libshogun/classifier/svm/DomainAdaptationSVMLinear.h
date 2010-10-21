/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2007-2010 Christian Widmer
 * Copyright (C) 2007-2010 Max-Planck-Society
 */

#ifndef _DomainAdaptation_SVM_LINEAR_H___
#define _DomainAdaptation_SVM_LINEAR_H___

#ifdef HAVE_LAPACK

#include "lib/common.h"
#include "classifier/svm/LibLinear.h"

#include <stdio.h>

namespace shogun
{
/** @brief class DomainAdaptiveSVMLinear */
#define IGNORE_IN_CLASSLIST
IGNORE_IN_CLASSLIST class CDomainAdaptationSVMLinear : public CLibLinear
{

	public:

		/** default constructor */
		CDomainAdaptationSVMLinear();


		/** constructor
		 *
		 * @param C cost constant C
		 * @param f features
		 * @param lab labels
		 * @param presvm trained SVM to regularize against
		 * @param B trade-off constant B
		 */
		CDomainAdaptationSVMLinear(float64_t C, CDotFeatures* f, CLabels* lab, CLinearClassifier* presvm, float64_t B);


		/** destructor */
		virtual ~CDomainAdaptationSVMLinear();


		/** init SVM
		 *
		 * @param presvm trained SVM to regularize against
		 * @param B trade-off constant B
		 * */
		void init(CLinearClassifier* presvm, float64_t B);



		/** train SVM classifier
		 *
		 * @param data training data (parameter can be avoided if distance or
		 * kernel-based classifiers are used and distance/kernels are
		 * initialized with train data)
		 *
		 * @return whether training was successful
		 */
		virtual bool train(CDotFeatures* data=NULL);


		/** get classifier type
		 *
		 * @return classifier type DASVMLINEAR
		 */
		virtual inline EClassifierType get_classifier_type() { return CT_DASVMLINEAR; }


		/** classify objects
		 *
		 * @param data (test)data to be classified
		 * @return classified labels
		 */
		virtual CLabels* classify(CDotFeatures* data);


		/** returns SVM that is used as prior information
		 *
		 * @return presvm
		 */
		virtual CLinearClassifier* get_presvm();


		/** getter for regularization parameter B
		 *
		 * @return regularization parameter B
		 */
		virtual float64_t get_B();


		/** getter for train_factor
		 *
		 * @return train_factor
		 */
		virtual float64_t get_train_factor();


		/** setter for train_factor
		 *
		 */
		virtual void set_train_factor(float64_t factor);

		/**
		 * get linear term
		 *
		 * @return lin the linear term
		 */
		//virtual std::vector<float64_t> get_linear_term();


		/**
		 * set linear term of the QP
		 *
		 * @param lin the linear term
		 */
		//virtual void set_linear_term(std::vector<float64_t> lin);


		/** @return object name */
		inline virtual const char* get_name() const { return "DomainAdaptationSVMLinear"; }


	private:

#ifdef HAVE_BOOST_SERIALIZATION
		friend class ::boost::serialization::access;
		// When the class Archive corresponds to an output archive, the
		// & operator is defined similar to <<.  Likewise, when the class Archive
		// is a type of input archive the & operator is defined similar to >>.
		template<class Archive>
		void serialize(Archive & ar, const unsigned int archive_version)
		{

			SG_DEBUG("archiving CDomainAdaptationSVMLinear\n");

			// serialize base class
			ar & ::boost::serialization::base_object<CLibLinear>(*this);

			// serialize remaining fields
			ar & presvm;

			ar & B;

			ar & train_factor;

			SG_DEBUG("done archiving CDomainAdaptationSVMLinear\n");

		}
#endif //HAVE_BOOST_SERIALIZATION

	protected:

		/** check sanity of presvm
		 *
		 * @return true if sane, throws SG_ERROR otherwise
		 */
		virtual bool is_presvm_sane();


		/** SVM to regularize against */
		CLinearClassifier* presvm;


		/** regularization parameter B */
		float64_t B;


		/** flag to switch off regularization in training */
		float64_t train_factor;


};
}


#endif //HAVE_LAPACK
#endif //_DomainAdaptation_SVM_LINEAR_H___
