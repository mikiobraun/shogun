function y = set_distance()
	global distance_name;
	global name;
	global feats_train;
	global feats_test;
	global distance;
	global kernel_arg1_distance;
	y=false;

	if !isempty(distance_name)
		dname=distance_name;
	elseif !isempty(kernel_arg1_distance)
		dname=kernel_arg1_distance;
	else
		dname=name;
	end

	if strcmp(dname, 'CanberraMetric')==1
		global CanberraMetric;
		distance=CanberraMetric(feats_train, feats_train);

	elseif strcmp(dname, 'CanberraWordDistance')==1
		global CanberraWordDistance;
		distance=CanberraWordDistance(feats_train, feats_train);

	elseif strcmp(dname, 'ChebyshewMetric')==1
		global ChebyshewMetric;
		distance=ChebyshewMetric(feats_train, feats_train);

	elseif strcmp(dname, 'EuclidianDistance')==1
		global EuclidianDistance;
		distance=EuclidianDistance(feats_train, feats_train);

	elseif strcmp(dname, 'GeodesicMetric')==1
		global GeodesicMetric;
		distance=GeodesicMetric(feats_train, feats_train);

	elseif strcmp(dname, 'HammingWordDistance')==1
		global HammingWordDistance;
		global distance_arg0_use_sign;
		distance=HammingWordDistance(feats_train, feats_train, tobool(distance_arg0_use_sign));

	elseif strcmp(dname, 'JensenMetric')==1
		global JensenMetric;
		distance=JensenMetric(feats_train, feats_train);

	elseif strcmp(dname, 'ManhattanMetric')==1
		global ManhattanMetric;
		distance=ManhattanMetric(feats_train, feats_train);

	elseif strcmp(dname, 'ManhattanWordDistance')==1
		global ManhattanWordDistance;
		distance=ManhattanWordDistance(feats_train, feats_train);

	elseif strcmp(dname, 'MinkowskiMetric')==1
		global MinkowskiMetric;
		global distance_arg0_k;
		distance=MinkowskiMetric(feats_train, feats_train, distance_arg0_k);

	elseif strcmp(dname, 'SparseEuclidianDistance')==1
		global SparseEuclidianDistance;
		distance=SparseEuclidianDistance(feats_train, feats_train);

	else
		error('Unknown distance %s!', dname);
	end

	y=true;