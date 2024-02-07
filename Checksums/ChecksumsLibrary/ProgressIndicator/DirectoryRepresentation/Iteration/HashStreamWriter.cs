using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Iteration
{
    public class HashStreamWriter : AbstractFileSystemVisitor, ProcessedFileObservable, ProcessedFileObserver
    {
        private IChecksumClaculator calculator;
        private IList<ProcessedFileObserver> observers;

        public HashStreamWriter(IChecksumClaculator calculator, Stream writer) : base(writer)
        {
            this.calculator = calculator;

            this.observers = new List<ProcessedFileObserver>();
        }

        public void changeCalculator(IChecksumClaculator newCalculator)
        {
            this.calculator = newCalculator;
        }

        public void addObserver(ProcessedFileObserver observer)
        {
            this.observers.Add(observer);
        }

        public void calculate(Stream inputStream, string fileName)
        {
            byte[] str = Encoding.ASCII
                .GetBytes(this.calculator.calculate(inputStream, fileName) + " : " + fileName + Environment.NewLine);
            this.writer.Write(str, 0, str.Length);
        }

        public override void visitDirectory(Directory directory)
        {
            traverseDirectory(directory);
        }

        public override void visitFile(File file)
        {
            try
            {
                this.calculate(new FileStream(file.Path, FileMode.Open), file.Path);
                //notifyObserversForProcessedFile(file.Path);
            }
            catch (UnauthorizedAccessException)
            {
                this.writer.Write(Encoding.ASCII
                .GetBytes("Access to file denied!!!" + Environment.NewLine));
            }
        }

        public void notifyObserversForProcessedFile(string fileName, long bytesProcessed = -1)
        {
            foreach (var observer in observers)
            {
                observer.handleProcessedFile(fileName, bytesProcessed);
            }
        }

        public void handleProcessedFile(string name, long bytesProcessed)
        {
            this.notifyObserversForProcessedFile(name, bytesProcessed);
        }
    }
}
