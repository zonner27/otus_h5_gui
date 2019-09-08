#ifndef DOCUMENT213108092019_H
#define DOCUMENT213108092019_H

#include <iostream>
#include "graphic_elements.h"

class Document {

public:
    void create_doc()
    {
        std::cout << "Create new document" << std::endl;
    }

    void import_doc(const std::string& name)
    {
        std::cout << "Import document " << name << std::endl;
    }

    void export_doc(const std::string& name)
    {
        std::cout << "Export document " << name << std::endl;
    }

    void draw_elements(GraphicElements* element)
    {
        element->create();
    }

    void remove_elements(GraphicElements* element)
    {
        element->remove();
    }
};

class Command {
public:
    virtual ~Command() = default;

    virtual void execute() = 0;

protected:
    explicit Command(Document* d)
            :document(d) { }

    Document* document;
};

class NewDocumentCommand : public Command {
public:
    explicit NewDocumentCommand(Document* d)
            :Command(d) { }

    void execute() override
    {
        document->create_doc();
    }
};

class ImportDocumentCommand : public Command {
    std::string name;
public:
    explicit ImportDocumentCommand(Document* d, std::string name_)
            :Command(d), name(std::move(name_)) { }

    void execute() override
    {
        document->import_doc(name);
    }
};

class ExportDocumentCommand : public Command {
    std::string name;
public:
    explicit ExportDocumentCommand(Document* d, std::string name_)
            :Command(d), name(std::move(name_)) { }

    void execute() override
    {
        document->export_doc(name);
    }
};

class DrawElements : public Command {
    GraphicElements* element;
public:
    explicit DrawElements(Document* d, GraphicElements* element_)
            :Command(d), element(std::move(element_)) { }

    void execute() override
    {
        document->draw_elements(element);
    }
};

class RemoveElements : public Command {
    GraphicElements* element;
public:
    explicit RemoveElements(Document* d, GraphicElements* element_)
            :Command(d), element(std::move(element_)) { }

    void execute() override
    {
        document->remove_elements(element);
    }
};

#endif //DOCUMENT213108092019_H
