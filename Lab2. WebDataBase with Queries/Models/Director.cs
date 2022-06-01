using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace MovieBase
{
    public partial class Director
    {
        public Director()
        {
            DirectorMovies = new HashSet<DirectorMovie>();
        }

        public int Id { get; set; }

        [Display(Name = "Ім'я режисера")]
        public string Name { get; set; } = null!;

        [Display(Name = "Фільми")]
        public virtual ICollection<DirectorMovie> DirectorMovies { get; set; }
    }
}
