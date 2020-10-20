//
// Created by kiper220 on 09.10.2020.
//

#ifndef REDTEXT_PARSER_H
#define REDTEXT_PARSER_H
#include <nlohmann/json.hpp>
#include <Lexer.h>

namespace RT{
    namespace Parser{
        class AnalyzerVisitor;

        class ParserInterface{
        public:
            ParserInterface(list<pair<Lexer::LexiconType, string>>::iterator iterator_begin, list<pair<Lexer::LexiconType, string>>::iterator iterator_end);
            void setVisitorList(vector<shared_ptr<AnalyzerVisitor>> visitorVector);

            virtual pair<nlohmann::json, int> acceptAllReturn() = 0;
            virtual void acceptAll() = 0;

            virtual list<pair<Lexer::LexiconType, string>>::iterator& begin() = 0;
            virtual list<pair<Lexer::LexiconType, string>>::iterator& end() = 0;

            virtual explicit operator string() = 0;
            virtual explicit operator nlohmann::json&() = 0;

        protected:
            virtual void accept(AnalyzerVisitor& visitor) = 0;

            nlohmann::json parsingData;

            list<pair<Lexer::LexiconType, string>>::iterator iterator_begin;
            list<pair<Lexer::LexiconType, string>>::iterator iterator_end;

            vector<shared_ptr<AnalyzerVisitor>> visitorList;
        };

        class STDParser : public ParserInterface{
        public:
            STDParser(list<pair<Lexer::LexiconType, string>>::iterator iterator_begin, list<pair<Lexer::LexiconType, string>>::iterator iterator_end);

            pair<nlohmann::json, int> acceptAllReturn() override;
            void acceptAll() override;

            list<pair<Lexer::LexiconType, string>>::iterator& begin() override;
            list<pair<Lexer::LexiconType, string>>::iterator& end() override;

            explicit operator string() override;
            explicit operator nlohmann::json&() override;

        protected:

            void accept(AnalyzerVisitor& visitor) override;
        };

        class AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) = 0;
        };

        class Module: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ModuleDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclDefs: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclDef: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AttributeSpecifier: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Declaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Constructor: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Destructor: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Postblit: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Allocator: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Deallocator: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ClassInvariant: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StructInvariant: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class UnitTest: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AliasThis: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticConstructor: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticDestructor: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SharedStaticConstructor: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SharedStaticDestructor: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ConditionalDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DebugSpecification: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VersionSpecification: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticAssert: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateMixinDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateMixin: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MixinDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ModuleAttributes: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ModuleFullyQualifiedName: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ModuleAttribute: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeprecatedAttribute: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class UserDefinedAttribute: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ModuleName: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Packages: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class PackageName: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ImportDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ImportList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Import: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ImportBindings: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ModuleAliasIdentifier: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ImportBindList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ImportBind: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ArgumentList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VarDeclarations: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AliasDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AggregateDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticForeachDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StorageClasses: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BasicType: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Declarators: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AutoDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclaratorInitializer: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclaratorIdentifierList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VarDeclarator: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateParameters: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AltDeclarator: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclaratorIdentifier: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VarDeclaratorIdentifier: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AltDeclaratorIdentifier: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Declarator: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BasicType2: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AltDeclaratorSuffixes: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AltFuncDeclaratorSuffix: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AltDeclaratorX: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AltDeclaratorSuffix: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AssignExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Type: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Parameters: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MemberFunctionAttributes: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeCtors: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeCtor: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BasicTypeX: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IdentifierList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Typeof: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Vector: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Traits: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MixinType: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VectorBaseType: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BasicType2X: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionAttributes: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateInstance: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StorageClass: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class LinkageAttribute: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AlignAttribute: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Property: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Initializer: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VoidInitializer: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NonVoidInitializer: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ExpInitializer: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ArrayInitializer: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StructInitializer: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ArrayMemberInitializations: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ArrayMemberInitialization: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StructMemberInitializers: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StructMemberInitializer: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AutoDeclarationX: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AutoDeclarationY: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncDeclarator: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionLiteral: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Expression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Attribute: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclarationBlock: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VisibilityAttribute: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Pragma: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AtAttribute: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class LinkageType: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NamespaceList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ConditionalExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CommaExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class OrOrExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AndAndExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class OrExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class XorExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AndExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CmpExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ShiftExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EqualExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IdentityExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class RelExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AddExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MulExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CatExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class UnaryExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ComplementExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeleteExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CastExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class PowExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NewExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NewExpressionWithArgs: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NewAnonClassExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AllocatorArguments: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class PostfixExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class PrimaryExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IndexExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SliceExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Slice: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IntegerLiteral: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FloatLiteral: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CharacterLiteral: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StringLiterals: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ArrayLiteral: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AssocArrayLiteral: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AssertExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MixinExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ImportExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeidExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IsExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SpecialKeyword: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TraitsExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StringLiteral: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class KeyValuePairs: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class KeyValuePair: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class KeyExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ValueExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ParameterWithAttributes: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionLiteralBody: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ParameterWithMemberAttributes: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Lambda: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BlockStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionContracts: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BodyStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AssertArguments: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeSpecialization: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateParameterList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Statement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NoScopeNonEmptyStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NoScopeStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NonEmptyOrScopeBlockStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NonEmptyStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NonEmptyStatementNoCaseNoDefault: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ScopeStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ScopeBlockStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class LabeledStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StatementList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ExpressionStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclarationStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IfStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IfCondition: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ThenStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ElseStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class WhileStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DoStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Initialize: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Test: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Increment: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AggregateForeach: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachTypeList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachAggregate: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Foreach: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachType: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachTypeAttributes: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachTypeAttribute: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class RangeForeach: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class LwrExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class UprExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachRangeStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SwitchStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CaseStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CaseRangeStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FirstExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class LastExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DefaultStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ScopeStatementList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StatementListNoCaseNoDefault: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StatementNoCaseNoDefault: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FinalSwitchStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ContinueStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BreakStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ReturnStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class GotoStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class WithStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SynchronizedStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TryStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Catches: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Catch: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CatchParameter: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FinallyStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ThrowStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ScopeGuardStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmInstructionList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class PragmaStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MixinStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StructDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AnonStructDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class UnionDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AnonUnionDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AggregateBody: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ClassDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BaseClassList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SuperClass: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Interfaces: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Interface: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ConstructorArgs: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InterfaceDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BaseInterfaceList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumBaseType: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumBody: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumMembers: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumMemberAttributes: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumMemberAttribute: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumMember: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AnonymousEnumDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AnonymousEnumMembers: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AnonymousEnumMember: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AutoFuncDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncDeclaratorSuffix: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ParameterList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ParameterAttributes: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InOut: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VariadicArgumentsAttributes: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VariadicArgumentsAttribute: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionAttribute: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MemberFunctionAttribute: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionBody: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SpecifiedFunctionBody: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MissingFunctionBody: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionContract: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InOutContractExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InOutStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InContractExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class OutContractExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class OutStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateParameter: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateArguments: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateArgumentList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateArgument: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Symbol: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SymbolTail: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateSingleArgument: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateTypeParameter: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateTypeParameterSpecialization: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateTypeParameterDefault: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateThisParameter: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateValueParameter: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateValueParameterSpecialization: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateValueParameterDefault: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateAliasParameter: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateAliasParameterSpecialization: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateAliasParameterDefault: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateSequenceParameter: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ConstructorTemplate: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ClassTemplateDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InterfaceTemplateDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StructTemplateDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class UnionTemplateDeclaration: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Constraint: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MixinTemplateName: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class QualifiedIdentifierList: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ConditionalStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Condition: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VersionCondition: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DebugCondition: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticIfCondition: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticForeach: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticForeachStatement: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TraitsKeyword: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TraitsArguments: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TraitsArgument: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Operands: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IntegerExpression: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Register: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Register64: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Operand: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmLogOrExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmLogAndExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmOrExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmXorExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmAndExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmEqualExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmRelExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmShiftExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmAddExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmMulExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmBrExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmUnaExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmPrimaryExp: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DotIdentifier: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmTypePrefix: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NamedCharacterEntity: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MangledName: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class QualifiedName: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SymbolFunctionName: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SymbolName: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateInstanceName: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateID: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateArgs: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateArg: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateArgX: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Value: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class HexFloat: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Exponent: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class HexDigits: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class HexDigit: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CharWidth: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Name: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class LName: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeBackRef: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IdentifierBackRef: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NumberBackRef: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeX: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeModifiers: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Shared: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Const: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Immutable: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Wild: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeArray: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeStaticArray: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeAssocArray: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypePointer: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeVector: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeFunction: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeFunctionNoReturn: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CallConvention: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrs: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttr: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrPure: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrNogc: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrNothrow: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrProperty: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrRef: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrReturn: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrScope: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrTrusted: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrSafe: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrLive: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Parameter: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Parameter2: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ParamClose: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeIdent: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeClass: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeStruct: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeEnum: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeTypedef: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeDelegate: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeVoid: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeByte: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeUbyte: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeShort: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeUshort: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeInt: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeUint: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeLong: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeUlong: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeCent: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeUcent: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeFloat: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeDouble: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeReal: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeIfloat: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeIdouble: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeIreal: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeCfloat: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeCdouble: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeCreal: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeBool: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeChar: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeWchar: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeDchar: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeNull: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeTuple: public AnalyzerVisitor{
        public:
            virtual pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
    }
}

#endif //REDTEXT_PARSER_H
