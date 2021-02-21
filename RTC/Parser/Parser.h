//
// Created by kiper220 on 09.10.2020.
//

#include <nlohmann/json.hpp>
#include <Lexer.h>
/*
namespace RT{
    namespace Parser{
        class ParserSubprogram;
        class ParserInputInstance;
        class ParserSubprogram;
        class ParserUtilInstance;
        class ParserOutputInstance;

#ifndef REDTEXT_PARSER_H
#define REDTEXT_PARSER_H

        //////////////////////////////////////////// Интерфейсы, патерн Анализатор ////////////////////////////////////////////

        class ParserInputInstance{                                                                                      // Класс интерфейс для интерфейса передачи данных парсеру
        public:
            virtual vector<pair<InterfaceLexer::LexiconType, string>>& get() = 0;

            virtual vector<pair<InterfaceLexer::LexiconType, string>>::iterator& begin() = 0;
            virtual vector<pair<InterfaceLexer::LexiconType, string>>::iterator& end() = 0;

            virtual vector<pair<InterfaceLexer::LexiconType, string>>::iterator& rbegin() = 0;
            virtual vector<pair<InterfaceLexer::LexiconType, string>>::iterator& rend() = 0;
        };

        class ParserInstance{                                                                                           // Класс интерфейс логики обработки интерфейса поступаеммых данных, подпрограмм и интерфейса вывода
            virtual bool setParserInput(ParserInputInstance*) = 0;
            virtual ParserOutputInstance* getParserOutput() = 0;

            virtual bool setSubprogramsList(vector<ParserSubprogram*>) = 0;
            virtual vector<ParserSubprogram*>& getSubprogramsList() = 0;

            virtual bool Analyze() = 0;

            virtual vector<pair<InterfaceLexer::LexiconType, string>>::iterator& dataBegin() = 0;
            virtual vector<pair<InterfaceLexer::LexiconType, string>>::iterator& dataEnd() = 0;
        };

        class ParserSubprogramInstance{                                                                                 // Класс интерфейса подпрограммы, отвечающий за один из типов токенов, для нахождения которых используется список утилит
            virtual bool setParserUtilites(vector<vector<ParserUtilInstance*>>) = 0;
            virtual bool isCompliance(ParserInstance&) = 0;
            virtual pair<bool, nlohmann::json> Accomplishment(ParserInstance&) = 0;
        };
        class ParserUtilInstance{                                                                                       // Класс интерфейса утилиты подпрограммы, говорящий, является ли указанный токен соответствующим и подготавивает токен для обработки подпрограммой
            virtual bool isCompliance(vector<pair<InterfaceLexer::LexiconType, string>>::iterator&) = 0;
            virtual pair<bool, nlohmann::json> Accomplishment(vector<pair<InterfaceLexer::LexiconType, string>>::iterator&) = 0;
        };

        class ParserOutputInstance {                                                                                    // Класс интерфейса получения данных из парсера
            virtual bool set(nlohmann::json) = 0;
        };

        //////////////////////////////////////////// Классы парсера языка RedText, патерн Анализатор ////////////////////////////////////////////

        class RedTextParserInput: public ParserInputInstance{                                                           // Реализация класса передачи данных парсеру языка RedText
        public:
            RedTextParserInput(vector<pair<InterfaceLexer::LexiconType, string>>);
            RedTextParserInput(RedTextParserInput& stdParserInput);

            vector<pair<InterfaceLexer::LexiconType, string>>& get() override;

            vector<pair<InterfaceLexer::LexiconType, string>>::iterator& begin() override;
            vector<pair<InterfaceLexer::LexiconType, string>>::iterator& end() override;

            vector<pair<InterfaceLexer::LexiconType, string>>::iterator& rbegin() override;
            vector<pair<InterfaceLexer::LexiconType, string>>::iterator& rend() override;

        private:
            vector<pair<InterfaceLexer::LexiconType, string>> ParserInputData;
        };

        class RedTextParserOutput: public ParserOutputInstance {                                                        // Реализация класса получения данных от парсера языка RedText
            bool set(nlohmann::json) override;
            nlohmann::json&& get();

        private:
            nlohmann::json OutputData;
        };

        class RedTextParser: public ParserInstance{                                                                     // Реализация класса парсера языка RedText
        public:
            RedTextParser();
            RedTextParser(RedTextParser& stdParser);

            bool setParserInput(ParserInputInstance *parserInputInstance) override;
            bool setSubprogramsList(vector<ParserSubprogram*>) override;
            vector<ParserSubprogram*>& getSubprogramsList() override;

            bool Analyze() override;

            vector<pair<InterfaceLexer::LexiconType, string>>::iterator& dataBegin() override;
            vector<pair<InterfaceLexer::LexiconType, string>>::iterator& dataEnd() override;

        private:
            RedTextParserInput parserInput;
            RedTextParserOutput parserOutput;
        };




        class Module: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ModuleDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclDefs: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclDef: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AttributeSpecifier: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Declaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Constructor: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Destructor: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Postblit: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Allocator: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Deallocator: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ClassInvariant: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StructInvariant: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class UnitTest: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AliasThis: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticConstructor: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticDestructor: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SharedStaticConstructor: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SharedStaticDestructor: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ConditionalDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DebugSpecification: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VersionSpecification: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticAssert: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateMixinDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateMixin: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MixinDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ModuleAttributes: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ModuleFullyQualifiedName: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ModuleAttribute: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeprecatedAttribute: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class UserDefinedAttribute: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ModuleName: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Packages: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class PackageName: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ImportDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ImportList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Import: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ImportBindings: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ModuleAliasIdentifier: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ImportBindList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ImportBind: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ArgumentList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VarDeclarations: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AliasDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AggregateDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticForeachDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StorageClasses: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BasicType: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Declarators: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AutoDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclaratorInitializer: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclaratorIdentifierList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VarDeclarator: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateParameters: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AltDeclarator: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclaratorIdentifier: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VarDeclaratorIdentifier: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AltDeclaratorIdentifier: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Declarator: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BasicType2: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AltDeclaratorSuffixes: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AltFuncDeclaratorSuffix: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AltDeclaratorX: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AltDeclaratorSuffix: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AssignExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Type: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Parameters: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MemberFunctionAttributes: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeCtors: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeCtor: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BasicTypeX: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IdentifierList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Typeof: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Vector: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Traits: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MixinType: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VectorBaseType: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BasicType2X: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionAttributes: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateInstance: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StorageClass: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class LinkageAttribute: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AlignAttribute: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Property: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Initializer: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VoidInitializer: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NonVoidInitializer: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ExpInitializer: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ArrayInitializer: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StructInitializer: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ArrayMemberInitializations: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ArrayMemberInitialization: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StructMemberInitializers: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StructMemberInitializer: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AutoDeclarationX: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AutoDeclarationY: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncDeclarator: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionLiteral: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Expression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Attribute: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclarationBlock: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VisibilityAttribute: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Pragma: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AtAttribute: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class LinkageType: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NamespaceList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ConditionalExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CommaExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class OrOrExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AndAndExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class OrExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class XorExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AndExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CmpExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ShiftExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EqualExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IdentityExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class RelExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AddExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MulExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CatExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class UnaryExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ComplementExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeleteExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CastExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class PowExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NewExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NewExpressionWithArgs: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NewAnonClassExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AllocatorArguments: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class PostfixExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class PrimaryExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IndexExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SliceExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Slice: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IntegerLiteral: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FloatLiteral: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CharacterLiteral: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StringLiterals: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ArrayLiteral: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AssocArrayLiteral: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AssertExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MixinExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ImportExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeidExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IsExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SpecialKeyword: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TraitsExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StringLiteral: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class KeyValuePairs: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class KeyValuePair: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class KeyExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ValueExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ParameterWithAttributes: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionLiteralBody: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ParameterWithMemberAttributes: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Lambda: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BlockStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionContracts: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BodyStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AssertArguments: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeSpecialization: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateParameterList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Statement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NoScopeNonEmptyStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NoScopeStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NonEmptyOrScopeBlockStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NonEmptyStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NonEmptyStatementNoCaseNoDefault: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ScopeStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ScopeBlockStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class LabeledStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StatementList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ExpressionStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DeclarationStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IfStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IfCondition: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ThenStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ElseStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class WhileStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DoStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Initialize: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Test: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Increment: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AggregateForeach: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachTypeList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachAggregate: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Foreach: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachType: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachTypeAttributes: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachTypeAttribute: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class RangeForeach: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class LwrExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class UprExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ForeachRangeStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SwitchStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CaseStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CaseRangeStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FirstExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class LastExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DefaultStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ScopeStatementList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StatementListNoCaseNoDefault: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StatementNoCaseNoDefault: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FinalSwitchStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ContinueStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BreakStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ReturnStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class GotoStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class WithStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SynchronizedStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TryStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Catches: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Catch: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CatchParameter: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FinallyStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ThrowStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ScopeGuardStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmInstructionList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class PragmaStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MixinStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StructDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AnonStructDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class UnionDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AnonUnionDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AggregateBody: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ClassDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BaseClassList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SuperClass: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Interfaces: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Interface: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ConstructorArgs: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InterfaceDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class BaseInterfaceList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumBaseType: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumBody: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumMembers: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumMemberAttributes: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumMemberAttribute: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class EnumMember: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AnonymousEnumDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AnonymousEnumMembers: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AnonymousEnumMember: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AutoFuncDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncDeclaratorSuffix: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ParameterList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ParameterAttributes: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InOut: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VariadicArgumentsAttributes: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VariadicArgumentsAttribute: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionAttribute: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MemberFunctionAttribute: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionBody: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SpecifiedFunctionBody: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MissingFunctionBody: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FunctionContract: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InOutContractExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InOutStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InContractExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class OutContractExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class OutStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateParameter: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateArguments: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateArgumentList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateArgument: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Symbol: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SymbolTail: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateSingleArgument: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateTypeParameter: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateTypeParameterSpecialization: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateTypeParameterDefault: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateThisParameter: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateValueParameter: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateValueParameterSpecialization: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateValueParameterDefault: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateAliasParameter: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateAliasParameterSpecialization: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateAliasParameterDefault: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateSequenceParameter: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ConstructorTemplate: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ClassTemplateDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class InterfaceTemplateDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StructTemplateDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class UnionTemplateDeclaration: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Constraint: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MixinTemplateName: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class QualifiedIdentifierList: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ConditionalStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Condition: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class VersionCondition: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DebugCondition: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticIfCondition: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticForeach: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class StaticForeachStatement: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TraitsKeyword: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TraitsArguments: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TraitsArgument: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Operands: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IntegerExpression: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Register: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Register64: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Operand: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmLogOrExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmLogAndExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmOrExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmXorExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmAndExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmEqualExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmRelExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmShiftExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmAddExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmMulExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmBrExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmUnaExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmPrimaryExp: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class DotIdentifier: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class AsmTypePrefix: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NamedCharacterEntity: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class MangledName: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class QualifiedName: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SymbolFunctionName: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class SymbolName: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateInstanceName: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateID: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateArgs: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateArg: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TemplateArgX: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Value: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class HexFloat: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Exponent: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class HexDigits: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class HexDigit: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CharWidth: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Name: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class LName: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeBackRef: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class IdentifierBackRef: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class NumberBackRef: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeX: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeModifiers: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Shared: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Const: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Immutable: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Wild: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeArray: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeStaticArray: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeAssocArray: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypePointer: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeVector: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeFunction: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeFunctionNoReturn: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class CallConvention: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrs: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttr: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrPure: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrNogc: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrNothrow: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrProperty: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrRef: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrReturn: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrScope: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrTrusted: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrSafe: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class FuncAttrLive: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Parameter: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class Parameter2: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class ParamClose: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeIdent: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeClass: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeStruct: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeEnum: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeTypedef: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeDelegate: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeVoid: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeByte: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeUbyte: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeShort: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeUshort: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeInt: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeUint: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeLong: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeUlong: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeCent: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeUcent: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeFloat: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeDouble: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeReal: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeIfloat: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeIdouble: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeIreal: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeCfloat: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeCdouble: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeCreal: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeBool: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeChar: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeWchar: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeDchar: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeNull: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };
        class TypeTuple: public AnalyzerVisitor{
        public:
            pair<nlohmann::json, bool> visitParser(STDParser& parser) override;
        };

    }
}

#endif //REDTEXT_PARSER_H
*/
