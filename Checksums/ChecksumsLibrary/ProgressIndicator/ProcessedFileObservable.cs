using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator
{
    public interface ProcessedFileObservable
    {
        void notifyObserversForProcessedFile(string fileName, long bytesProcessed = -1);

        void addObserver(ProcessedFileObserver observer);
    }
}
