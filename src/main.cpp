#include <vector>
#include <memory>
#include "graphic_elements.h"
#include "document.h"

int main()
{
    try
    {
        std::unique_ptr<Document> doc;
        //std::vector<Command*> history;
        std::vector<std::unique_ptr<Command>> history;

        history.push_back(std::move(new NewDocumentCommand(doc.get())));
        history.push_back(new ImportDocumentCommand(doc.get(), "File.txt"));
        history.push_back(new ExportDocumentCommand(doc.get(), "File.txt"));

        std::unique_ptr<GraphicElements> circle(new Circle);

        history.push_back(new DrawElements(doc.get(), circle.get()));
        history.push_back(new RemoveElements(doc.get(), circle.get()));

        std::unique_ptr<GraphicElements> circle_frame(new CircleWithFrame(circle.get()));
        history.push_back(new DrawElements(doc.get(), circle_frame.get()));
        history.push_back(new RemoveElements(doc.get(), circle_frame.get()));

        std::unique_ptr<GraphicElements> square(new Square);
        history.push_back(new DrawElements(doc.get(), square.get()));
        history.push_back(new RemoveElements(doc.get(), square.get()));

        for (auto c: history)
        {
            c->execute();
        }

        //delete circle;
        //delete circle_frame;
        //delete square;
//        for (auto c: history)
//        {
//            delete c;
//        }

    } catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    return 0;
}
