using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;

namespace MovieBase.Models
{
    public class Query
    {
        public string QueryId { get; set; }

        public string Error { get; set; }
        public int ErrorFlag { get; set; }
        public double Rating { get; set; }
        public string ActorName { get; set; }

        public string GenreName { get; set; }
        public string GenreName1 { get; set; }
        public string DirectorName { get; set; }


        [Required(ErrorMessage = "Поле не повинне бути порожнім")]
        [Display(Name = "Рік")]
        public int MovieYear { get; set; }

        [Required(ErrorMessage = "Поле не повинне бути порожнім")]
        public int CountOfGenres { get; set; }
        public string MovieName { get; set; }
        public string ProductionName { get; set; }

        public List<string>? MoviesNames { get; set; }
        public List<string>? ProductionNames { get; set; }
        public List<string>? ActorsNames { get; set; }
        public List<string>? GenresNames { get; set; }
        public List<int>? MoviesYears { get; set; }
        public List<string>? DirectorsNames { get; set; }

    }
}