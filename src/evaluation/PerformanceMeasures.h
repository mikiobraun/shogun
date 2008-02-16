/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2008 Sebastian Henschel
 * Copyright (C) 2008 Friedrich Miescher Laboratory of Max-Planck-Society
 */

#ifndef __PERFORMANCEMEASURES_H_
#define __PERFORMANCEMEASURES_H_

#include "base/SGObject.h"
#include "features/Labels.h"
#include "lib/DynamicArray.h"

/**
 * class to implement various performance measures, like:
 * ROC, PRC, DET, CC, WR accuracy, balance
 *
 * based on:
 * Fawcett, T: March 2004, ROC Graphs: Notes and Practical
 * Considerations for Researchers
 *
 * @author Sebastian Henschel <shogun@kodeaffe.de>
 */
class CPerformanceMeasures : public CSGObject
{
	public:
		/** default constructor */
		CPerformanceMeasures();

		/** constructor
		 *
		 * @param true_labels_ true labels as seen in real world
		 * @param output_ output labels/hypothesis from a classifier
		 */
		CPerformanceMeasures(CLabels* true_labels_, CLabels* output_);

		virtual ~CPerformanceMeasures();

		/** initialise performance measures
		 *
		 * @param true_labels_ true labels as seen in real world
		 * @param output_ output labels/hypothesis from a classifier
		 * @throws ShogunException
		 * @return if initialising was successful
		 */
		void init(CLabels* true_labels_, CLabels* output_);

		/** set true labels as seen in real world
		 *
		 * @param true_labels_ true labels
		 * @return if setting was successful
		 */
		inline bool set_true_labels(CLabels* true_labels_)
		{
			true_labels=true_labels_;
			SG_REF(true_labels);
			return true;
		}

		/** get true labels as seen in real world
		 *
		 * @return true labels as seen in real world
		 */
		inline CLabels* get_true_labels() const { return true_labels; }

		/** set output labels/hypothesis from a classifier
		 *
		 * @param output_ output labels
		 * @return if setting was successful
		 */
		inline bool set_output(CLabels* output_)
		{
			output=output_;
			SG_REF(output);
			return true;
		}

		/** get output labels/hypothesis from a classifier
		 *
		 * @return output labels
		 */
		inline CLabels* get_output() const { return output; }

		/** get number of labels in output/true labels
		 *
		 * @return number of labels in output/true labels
		 */
		inline INT get_num_labels() const { return num_labels; }

		/** get classifier's accuracy at threshold 0
		 *
		 * @throws ShogunException
		 * @return classifer's accuracy at threshold 0
		 */
		DREAL get_accuracy0();

		/** get ROC for previously given labels (swig compatible)
		 * caller has to free
		 *
		 * @param result where computed ROC values will be stored
		 * @param dim number of labels/examples
		 * @param num number of elements in each result (== 2)
		 */
		void get_ROC(DREAL** result, INT* dim, INT* num);

		/** return area under ROC
		 *
		 * @return area under ROC
		 */
		inline DREAL get_auROC()
		{
			if (auROC==0.) {
				DREAL** roc;
				compute_ROC(roc);
				free(*roc);
			}
			return auROC;
		}

		/** return area over ROC
		 *
		 * @return area over ROC
		 */
		inline DREAL get_aoROC()
		{
			if (auROC==0.) {
				DREAL** roc;
				compute_ROC(roc);
				free(*roc);
			}
			return 1.-auROC;
		}

		/** get classifier's accuracy aligned to ROC (swig compatible)
		 * caller has to free
		 *
		 * @param result where accuracy will be stored
		 * @param num number of accuracy values
		 */
		void get_accuracyROC(DREAL** result, INT* num);

		/** get classifier's error rate aligned to ROC (swig compatible)
		 * caller has to free
		 *
		 * @param result where error will be stored
		 * @param num number of error values
		 */
		void get_errorROC(DREAL** result, INT* num);

		/** get PRC for previously given labels (swig compatible)
		 * caller has to free
		 *
		 * @param result where computed ROC values will be stored
		 * @param dim number of labels/examples
		 * @param num number of elements in each result (== 2)
		 */
		void get_PRC(DREAL** result, INT* dim, INT* num);

		/** return area under PRC
		 *
		 * @return area under PRC
		 */
		inline DREAL get_auPRC()
		{
			if (auPRC==0.) {
				DREAL** prc;
				compute_PRC(prc);
				free(*prc);
			}
			return auPRC;
		}

		/** return area over PRC
		 *
		 * @return area over PRC
		 */
		inline DREAL get_aoPRC()
		{
			if (auPRC==0.) {
				DREAL** prc;
				compute_PRC(prc);
				free(*prc);
			}
			return 1.-auPRC;
		}

		/** get classifier's F-measure aligned to PRC (swig compatible)
		 * caller has to free
		 *
		 * @param result where F-measure will be stored
		 * @param num number of F-measure values
		 * @throws ShogunException
		 */
		void get_fmeasurePRC(DREAL** result, INT* num);

		/** get classifier's F-measure at threshold 0
		 *
		 * @return classifer's F-measure at threshold 0
		 */
		DREAL get_fmeasure0();

		/** get DET curve for previously given labels (swig compatible)
		 * caller has to free
		 *
		 * @param result where computed DET values will be stored
		 * @param dim number of labels/examples
		 * @param num number of elements in each result (== 2)
		 */
		void get_DET(DREAL** result, INT* dim, INT* num);

		/** return area under DET
		 *
		 * @return area under DET
		 */
		inline DREAL get_auDET()
		{
			if (auDET==0.) {
				DREAL** det;
				compute_DET(det);
				free(*det);
			}
			return auDET;
		}

		/** return area over DET
		 *
		 * @return area over DET
		 */
		inline DREAL get_aoDET()
		{
			if (auDET==0.) {
				DREAL** det;
				compute_DET(det);
				free(*det);
			}
			return 1.-auDET;
		}
		/** get classifier's CC (swig compatible)
		 * caller has to free
		 *
		 * @param result where CC will be stored
		 * @param num number of CC values
		 * @throws ShogunException
		 */
		void get_CC(DREAL** result, INT* num);

		/** get classifier's CC at threshold 0
		 *
		 * @return classifer's CC at threshold 0
		 */
		DREAL get_CC0();

		/** get classifier's WR accuracy (swig compatible)
		 * caller has to free
		 *
		 * @param result where WR accuracy will be stored
		 * @param num number of WR accuracy values
		 * @throws ShogunException
		 */
		void get_WRacc(DREAL** result, INT* num);

		/** get classifier's WR accuracy at threshold 0
		 *
		 * @return classifer's WR accuracy at threshold 0
		 */
		DREAL get_WRacc0();

		/** get classifier's balance (swig compatible)
		 * caller has to free
		 *
		 * @param result where balance will be stored
		 * @param num number of balance values
		 * @throws ShogunException
		 */
		void get_balance(DREAL** result, INT* num);

		/** get classifier's balance at threshold 0
		 *
		 * @return classifer's balance at threshold 0
		 */
		DREAL get_balance0();

	protected:
		/** true labels/examples as seen in real world */
		CLabels* true_labels;
		/** output labels/hypothesis from a classifier */
		CLabels* output;
		/** number of true labels/outputs/accuracies/ROC points */
		INT num_labels;

		/** number of positive examples in true_labels */
		INT all_true;
		/** number of negative examples in true_labels */
		INT all_false;

		/** array of size num_labels with indices of true_labels/output
		 * sorted to fit ROC algorithm */
		INT* sortedROC;
		/** area under ROC; 1 - area over ROC */
		DREAL auROC;
		/** classifier's accuracy at threshold 0 */
		DREAL accuracy0;

		/** area under PRC; 1 - area over PRC */
		DREAL auPRC;
		/** classifier's F-measure at threshold 0 */
		DREAL fmeasure0;

		/** area under DET; 1 - area over DET */
		DREAL auDET;

		/** classifier's CC at threshold 0 */
		DREAL cc0;
		/** classifier's WR accuracy at threshold 0 */
		DREAL wr_acc0;
		/** classifier's balance at threshold 0 */
		DREAL balance0;

	private:
		/** calculate trapezoid area for auROC
		 *
		 * @param x1 x coordinate of point 1
		 * @param x2 x coordinate of point 2
		 * @param y1 y coordinate of point 1
		 * @param y2 y coordinate of point 2
		 * @return trapezoid area for auROC
		 */
		template <class T> DREAL trapezoid_area(T x1, T x2, T y1, T y2);

		/** create index for ROC sorting
		 *
		 * @throws ShogunException
		 */
		void create_sortedROC();
		
		/** compute ROC points and auROC
		 *
		 * @throws ShogunException
		 */
		void compute_ROC(DREAL** result);

		/** compute ROC accuracy/error
		 *
		 * @param result where the result will be stored
		 * @param do_error if error instead of accuracy shall be computed
		 * @throws ShogunException
		 */
		void compute_accuracyROC(DREAL** result, bool do_error=false);

		/** compute PRC points and auPRC
		 *
		 * @param result where the result will be stored
		 * @throws ShogunException
		 */
		void compute_PRC(DREAL** result);

		/** compute DET points and auDET
		 *
		 * @param result where the result will be stored
		 * @throws ShogunException
		 */
		void compute_DET(DREAL** result);

		/** check classifiers output against true labels
		 *
		 * not as efficient as the method applied to ROC, but useable by other
		 * curves
		 *
		 * caller has to delete
		 *
		 * @param threshold threshold to check against
		 * @throws ShogunException
		 * @return array of 4 values, the number of:
		 *         true positives, false positives, false negatives, true
		 *         negatives
		 */
		INT* check_classification(DREAL threshold);
};
#endif /* __PERFORMANCEMEASURES_H_ */