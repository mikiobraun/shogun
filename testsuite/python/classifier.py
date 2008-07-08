"""
Test Classifier
"""

from numpy import double
from sg import sg

import util


def _set_classifier (indata):
	if indata.has_key('classifier_labels'):
		sg('set_labels', 'TRAIN', double(indata['classifier_labels']))

	cname=util.fix_classifier_name_inconsistency(indata['name'])
	sg('new_classifier', cname)

	if indata.has_key('classifier_bias'):
		sg('svm_use_bias', True)
	else:
		sg('svm_use_bias', False)

	if indata.has_key('classifier_epsilon'):
		sg('svm_epsilon', indata['classifier_epsilon'])
	if indata.has_key('classifier_tube_epsilon'):
		sg('svr_tube_epsilon', indata['classifier_tube_epsilon'])
	if indata.has_key('classifier_max_train_time'):
		sg('svm_max_train_time', indata['classifier_max_train_time'])
	if indata.has_key('classifier_linadd_enabled'):
		sg('use_linadd', True)
	if indata.has_key('classifier_batch_enabled'):
		sg('use_batch_computation', True)
	if indata.has_key('classifier_num_threads'):
		sg('threads', indata['classifier_num_threads'])


def _train (indata):
	if indata['classifier_type']=='knn':
		sg('train_classifier', indata['classifier_k'])
	elif indata['classifier_type']=='lda':
		sg('train_classifier', indata['classifier_gamma'])
	elif indata['classifier_type']=='perceptron':
		# does not converge
		try:
			sg('train_classifier')
		except RuntimeError:
			import sys
			sys.exit(0)
	else:
		if indata.has_key('classifier_C'):
			sg('c', double(indata['classifier_C']))
		sg('train_classifier')


def _evaluate (indata):
	alphas=0
	bias=0
	sv=0

	if indata['classifier_type']=='knn':
		sg('init_distance', 'TEST')
	elif indata['classifier_type']=='lda':
		pass
	else:
		if indata.has_key('classifier_bias') and indata.has_key('classifier_alphas'):
			[b, weights]=sg('get_svm')
			weights=weights.T
			bias=abs(b-indata['classifier_bias'])
			alphas=max(abs(weights[0]-indata['classifier_alphas']))

			if indata.has_key('classifier_support_vectors'):
				sv=max(abs(weights[1]-indata['classifier_support_vectors']))

		sg('init_kernel', 'TEST')

	classified=max(abs(sg('classify')-indata['classifier_classified']))

	return util.check_accuracy(indata['classifier_accuracy'],
		alphas=alphas, bias=bias, sv=sv, classified=classified)

########################################################################
# public
########################################################################

def test (indata):
	try:
		util.set_features(indata)
	except NotImplementedError, e:
		print e
		return True

	if indata['classifier_type']=='kernel':
		util.set_and_train_kernel(indata)
	elif indata['classifier_type']=='knn':
		util.set_and_train_distance(indata)

	try:
		_set_classifier(indata)
	except RuntimeError:
		print "%s is disabled/unavailable!" % indata['name']
		return True

	_train(indata)

	return _evaluate(indata)
