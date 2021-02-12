//
// Created by kiper220 on 09.10.2020.
//

#include "Parser.h"
#include <iostream>

namespace RT{
    namespace Parser{


        /*

        pair<nlohmann::json, bool> Module::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ModuleDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DeclDefs::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DeclDef::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AttributeSpecifier::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Declaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Constructor::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Destructor::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Postblit::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Allocator::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Deallocator::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ClassInvariant::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StructInvariant::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> UnitTest::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AliasThis::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StaticConstructor::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StaticDestructor::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> SharedStaticConstructor::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> SharedStaticDestructor::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ConditionalDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DebugSpecification::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> VersionSpecification::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StaticAssert::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateMixinDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateMixin::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> MixinDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ModuleAttributes::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ModuleFullyQualifiedName::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ModuleAttribute::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DeprecatedAttribute::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> UserDefinedAttribute::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ModuleName::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Packages::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> PackageName::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ImportDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ImportList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Import::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ImportBindings::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ModuleAliasIdentifier::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ImportBindList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ImportBind::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ArgumentList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FuncDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> VarDeclarations::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AliasDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AggregateDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> EnumDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StaticForeachDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StorageClasses::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> BasicType::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Declarators::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AutoDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DeclaratorInitializer::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DeclaratorIdentifierList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> VarDeclarator::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateParameters::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AltDeclarator::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DeclaratorIdentifier::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> VarDeclaratorIdentifier::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AltDeclaratorIdentifier::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Declarator::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> BasicType2::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AltDeclaratorSuffixes::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AltFuncDeclaratorSuffix::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AltDeclaratorX::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AltDeclaratorSuffix::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AssignExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Type::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Parameters::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> MemberFunctionAttributes::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeCtors::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeCtor::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> BasicTypeX::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> IdentifierList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Typeof::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Vector::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Traits::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> MixinType::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> VectorBaseType::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> BasicType2X::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FunctionAttributes::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateInstance::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StorageClass::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> LinkageAttribute::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AlignAttribute::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Property::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Initializer::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> VoidInitializer::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> NonVoidInitializer::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ExpInitializer::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ArrayInitializer::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StructInitializer::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ArrayMemberInitializations::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ArrayMemberInitialization::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StructMemberInitializers::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StructMemberInitializer::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AutoDeclarationX::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AutoDeclarationY::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FuncDeclarator::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FunctionLiteral::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Expression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Attribute::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DeclarationBlock::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> VisibilityAttribute::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Pragma::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AtAttribute::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> LinkageType::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> NamespaceList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ConditionalExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> CommaExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> OrOrExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AndAndExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> OrExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> XorExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AndExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> CmpExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ShiftExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> EqualExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> IdentityExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> RelExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> InExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AddExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> MulExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> CatExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> UnaryExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ComplementExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DeleteExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> CastExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> PowExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> NewExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> NewExpressionWithArgs::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> NewAnonClassExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AllocatorArguments::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> PostfixExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> PrimaryExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> IndexExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> SliceExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Slice::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> IntegerLiteral::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FloatLiteral::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> CharacterLiteral::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StringLiterals::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ArrayLiteral::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AssocArrayLiteral::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AssertExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> MixinExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ImportExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeidExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> IsExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> SpecialKeyword::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TraitsExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StringLiteral::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> KeyValuePairs::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> KeyValuePair::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> KeyExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ValueExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ParameterWithAttributes::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FunctionLiteralBody::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ParameterWithMemberAttributes::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Lambda::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> BlockStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FunctionContracts::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> BodyStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AssertArguments::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeSpecialization::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateParameterList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Statement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> NoScopeNonEmptyStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> NoScopeStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> NonEmptyOrScopeBlockStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> NonEmptyStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> NonEmptyStatementNoCaseNoDefault::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ScopeStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ScopeBlockStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> LabeledStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StatementList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ExpressionStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DeclarationStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> IfStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> IfCondition::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ThenStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ElseStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> WhileStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DoStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ForStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Initialize::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Test::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Increment::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AggregateForeach::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ForeachTypeList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ForeachAggregate::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ForeachStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Foreach::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ForeachType::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ForeachTypeAttributes::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ForeachTypeAttribute::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> RangeForeach::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> LwrExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> UprExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ForeachRangeStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> SwitchStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> CaseStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> CaseRangeStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FirstExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> LastExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DefaultStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ScopeStatementList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StatementListNoCaseNoDefault::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StatementNoCaseNoDefault::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FinalSwitchStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ContinueStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ReturnStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> BreakStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> GotoStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> WithStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> SynchronizedStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TryStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Catches::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Catch::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> CatchParameter::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FinallyStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ThrowStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ScopeGuardStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmInstructionList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> PragmaStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> MixinStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StructDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AnonStructDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> UnionDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AnonUnionDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AggregateBody::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ClassDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> BaseClassList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> SuperClass::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Interfaces::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Interface::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ConstructorArgs::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> InterfaceDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> BaseInterfaceList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> EnumBaseType::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> EnumBody::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> EnumMembers::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> EnumMemberAttributes::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> EnumMemberAttribute::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> EnumMember::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AnonymousEnumDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AnonymousEnumMembers::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AnonymousEnumMember::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AutoFuncDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FuncDeclaratorSuffix::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ParameterList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ParameterAttributes::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> InOut::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> VariadicArgumentsAttributes::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> VariadicArgumentsAttribute::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FunctionAttribute::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> MemberFunctionAttribute::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FunctionBody::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> SpecifiedFunctionBody::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> MissingFunctionBody::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FunctionContract::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> InOutStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> InContractExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> OutContractExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> InStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> OutStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateParameter::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateArguments::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateArgumentList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateArgument::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Symbol::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> SymbolTail::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateSingleArgument::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateTypeParameter::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateTypeParameterSpecialization::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateTypeParameterDefault::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateThisParameter::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateValueParameter::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateValueParameterSpecialization::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateValueParameterDefault::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateAliasParameter::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateAliasParameterSpecialization::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateAliasParameterDefault::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateSequenceParameter::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ConstructorTemplate::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ClassTemplateDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> InterfaceTemplateDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StructTemplateDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> UnionTemplateDeclaration::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Constraint::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> MixinTemplateName::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> QualifiedIdentifierList::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> ConditionalStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Condition::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> VersionCondition::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DebugCondition::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StaticIfCondition::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StaticForeach::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> StaticForeachStatement::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TraitsKeyword::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TraitsArguments::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TraitsArgument::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Operands::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> IntegerExpression::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Register::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Register64::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Operand::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmLogOrExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmLogAndExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmOrExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmXorExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmAndExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmEqualExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmRelExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmShiftExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmAddExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmMulExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmBrExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmUnaExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmPrimaryExp::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> DotIdentifier::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> AsmTypePrefix::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> NamedCharacterEntity::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> MangledName::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> QualifiedName::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> SymbolFunctionName::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> SymbolName::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateInstanceName::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateID::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateArgs::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateArg::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TemplateArgX::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Value::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> HexFloat::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Exponent::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> HexDigits::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> HexDigit::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> CharWidth::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Name::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> LName::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeBackRef::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> IdentifierBackRef::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> NumberBackRef::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeX::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeModifiers::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Shared::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Const::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Immutable::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> Wild::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeArray::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeStaticArray::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeAssocArray::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypePointer::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeVector::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeFunction::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeFunctionNoReturn::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> CallConvention::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FuncAttrs::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FuncAttr::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FuncAttrPure::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FuncAttrNogc::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FuncAttrNothrow::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FuncAttrProperty::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FuncAttrRef::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> FuncAttrReturn::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeIdent::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeClass::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeStruct::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeEnum::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeTypedef::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeDelegate::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeVoid::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeByte::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeUbyte::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeShort::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeUshort::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeInt::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeUint::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeLong::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeUlong::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeCent::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeUcent::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeFloat::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeDouble::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeReal::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeIfloat::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeIdouble::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeIreal::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeCfloat::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeCdouble::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeCreal::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeBool::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeChar::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeWchar::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeDchar::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeTuple::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }

        pair<nlohmann::json, bool> TypeNull::visitParser(STDParser &parser) {
            return pair<nlohmann::json, bool>();
        }
        */
    }
}
