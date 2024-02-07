using ChecksumsLibrary.ProgressIndicator;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary
{
    public abstract class ChecksumCalculator : IChecksumClaculator
    {
        private IList<ProcessedFileObserver> observers;

        public ChecksumCalculator()
        {
            this.observers = new List<ProcessedFileObserver>();
        }

        public void addObserver(ProcessedFileObserver observer)
        {
            this.observers.Add(observer);
        }

        public abstract string calculate(Stream inputStream, string fileName);

        public void notifyObserversForProcessedFile(string fileName, long bytesProcessed = -1)
        {
            foreach (var observer in this.observers)
            {
                observer.handleProcessedFile(fileName, bytesProcessed);
            }
        }
    }
}
