//#include "RandomTransformationDecoratorBase.h"
//
//template<typename RandomFunctionClassType, typename RandomFunctionType>
//void RandomTransformationDecoratorBase<RandomFunctionClassType, RandomFunctionType>::initializeTransformations
//(std::vector<std::unique_ptr<TextTransformation>>& transformations)
//{
//	for (int i = 0; i < transformations.size(); i++)
//	{
//		this->transformations.push_back(std::move(transformations[i]));
//	}
//}
//
//template<typename RandomFunctionClassType, typename RandomFunctionType>
//RandomTransformationDecoratorBase<RandomFunctionClassType, RandomFunctionType>::RandomTransformationDecoratorBase
//(std::shared_ptr<Label> label,
//	std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
//	RandomFunctionType randomFunction)
//	: LabelDecoratorBase(label), randomFunction(randomFunction)
//{
//	initializeTransformations(textTranformations);
//}
//
//template<typename RandomFunctionClassType, typename RandomFunctionType>
//RandomTransformationDecoratorBase<RandomFunctionClassType, RandomFunctionType>::RandomTransformationDecoratorBase
//(std::unique_ptr<Label> label,
//	std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
//	RandomFunctionType randomFunction)
//	: LabelDecoratorBase(std::move(label)), randomFunction(randomFunction)
//{
//	initializeTransformations(textTranformations);
//}
//
//template<typename RandomFunctionClassType, typename RandomFunctionType>
//std::string RandomTransformationDecoratorBase<RandomFunctionClassType, RandomFunctionType>::getText() const
//{
//	// TODO:: Random Function should be inclusive
//	int index = randomFunction(0, this->transformations.size() - 1);
//
//	std::string str = this->sharedSubject != nullptr ?
//		this->sharedSubject->getText() :
//		this->movedSubject->getText();
//
//	str = this->transformations[index]->transform(str);
//	return str;
//}
